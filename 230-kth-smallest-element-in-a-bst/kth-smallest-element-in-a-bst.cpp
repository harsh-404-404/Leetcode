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
    int kthSmallest(TreeNode* root, int k) {
        if(k > 0) k = -k;
        if(!root) return k;

        k = kthSmallest(root->left,k);
        if(k >= 0) return k;

        if(++k == 0) return root->val; 
        
        k = kthSmallest(root->right,k);
        if(k >= 0) return k;
        
        return k;
    }
};