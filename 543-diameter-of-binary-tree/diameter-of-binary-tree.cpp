/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return somefunction(root).first;
    }
    
    std::pair<int,int> somefunction(TreeNode* node){
        if(node == nullptr) return {0,0};

        std::pair<int,int> left { somefunction(node->left) };
        std::pair<int,int> right { somefunction(node->right) };
        
        return {std::max(std::max(left.first,right.first),left.second + right.second),std::max(left.second,right.second) + 1};
    }
};