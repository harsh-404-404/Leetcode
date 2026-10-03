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
        if (mydepth(root) == 10001) return false;
        return true; 
    }

    int mydepth(TreeNode* node){
        if(node == nullptr) return 0;

        int left = mydepth(node->left);
        int right = mydepth(node->right);
        if(left == 10001 || right == 10001) return 10001;
        int diff = left - right;

        if(diff < -1 || diff > 1) return 10001;

        return std::max(left,right) + 1;
    }
};