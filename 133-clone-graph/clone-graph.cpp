/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    std::unordered_map<int, Node*> hash {};
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(hash.contains(node->val)) return hash[node->val];

        Node* curr { new Node(node->val) };
        hash[node->val] = curr;

        for(auto* neighbor : node->neighbors){
            curr->neighbors.emplace_back( cloneGraph(neighbor) );    
        }
        return curr;
    }
};