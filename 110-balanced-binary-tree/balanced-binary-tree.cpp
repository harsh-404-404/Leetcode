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
    bool isBalanced(TreeNode* root) {
        if (mydepth(root) == -1) return false;
        return true; 
    }

    int mydepth(TreeNode* node){
        if(node == nullptr) return 0;

        int left = mydepth(node->left);
        int right = mydepth(node->right);
        if(left == -1 || right == -1) return -1;
        int diff = left - right;

        if(diff < -1 || diff > 1) return -1;

        return std::max(left,right) + 1;
    }
};