/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = NULL;
        Node** ptr2 = &new_head;
        Node* ptr = head;

        std::unordered_map<Node*,Node*>  map {};
        while(ptr != NULL){
            *ptr2 = new Node{(ptr->val),NULL,NULL};
            map[ptr] = *ptr2;
            ptr2 = &((*ptr2)->next);
            ptr = ptr->next;
        }

        ptr = head;
        while(ptr != NULL){
            map[ptr]->random = map[ptr->random];
            ptr = ptr->next;
        }   
        return new_head;
    }

};