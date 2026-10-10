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
private:
    int MAX = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        return std::max(MAX,findmax(root));
    }

    int findmax(TreeNode* node){
        if(!node) return INT_MIN;

        int left = findmax(node->left);
        int right = findmax(node->right);

        MAX = std::max(MAX,std::max(0,left) + std::max(0,right) + node->val);
        return std::max(std::max(0,left),std::max(0,right)) + node->val;
    }
};