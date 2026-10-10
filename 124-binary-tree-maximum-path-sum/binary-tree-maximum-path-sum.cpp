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
    int maxPathSum(TreeNode* root) {
        auto op = findmax(root);
        return std::max(op.first,op.second);
    }

    std::pair<int,int> findmax(TreeNode* node){
        if(!node) return {INT_MIN,INT_MIN};
        auto left = findmax(node->left);
        auto right = findmax(node->right);

        int through = node->val
                    + std::max(0, left.second)
                    + std::max(0, right.second);

        int best = std::max({
            through,
            left.first,
            right.first,
            node->val
        });
        return {best,node->val + std::max({0,left.second,right.second})};
    }
};