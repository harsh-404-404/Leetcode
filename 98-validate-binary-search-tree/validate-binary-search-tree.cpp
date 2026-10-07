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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return test(root,(long)INT_MAX + 1,(long)INT_MIN - 1);
    }

    bool test(TreeNode* root,long max, long min){
        if(root->val >= max || root->val <= min) return false;

        bool left = (root->left) ? test(root->left,root->val,min) : true;
        bool right = (root->right) ? test(root->right,max,root->val) : true;
        return left && right;
    }
    
};