class LRUCache {
public:
    struct Node{
        int key {};
        int value {};
        Node* next {nullptr};
        Node* prev {nullptr};
    };

    int cap {};
    std::unordered_map<int, Node*> umap {};
    Node* head {nullptr};
    Node tail {0,0,nullptr,nullptr};

    LRUCache(int capacity) : cap {capacity} {
        umap.reserve(cap);
    }
    
    int get(int key) {
        if(!umap.contains(key)) return -1;

        Node* node = umap[key];
        go_front(node);
        
        return node->value;
    }

    void go_front(Node* a){
        if(a == head) return;

        a->prev->next = a->next;
        a->next->prev = a->prev;
        
        a->prev = nullptr;
        a->next = head;

        head->prev = a;
        head = a;
    }

    void put(int key, int value) {
    
        if(umap.contains(key)){
            Node* node = umap[key];

            node->value = value;
            go_front(node);

            return;

        }
        
        if(umap.size() == cap){
            go_front(tail.prev);

            umap.erase(head->key);
            umap[key] = head;
            
            head->key = key;
            head->value = value;

            return;
        }
        
        
        Node* temp = new Node{key,value,head, nullptr};
        
        if(head != nullptr){
            head->prev = temp;
        }
        else{
            temp->next = &tail;
            tail.prev = temp;
        }
        head = temp;
        umap[key] = temp;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */