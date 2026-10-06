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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        std::vector<std::vector<int>> ans {};
        std::queue<TreeNode*> qu {};

        qu.push(root);
        
        while(qu.size()){
            std::vector<int> atLevel{};

            int n = qu.size();
            for(int i = 0; i < n; ++i){
                auto x = qu.front();
                atLevel.push_back(x->val);

                if(x->left) qu.push(x->left);
                if(x->right) qu.push(x->right);

                qu.pop();
            }
            ans.push_back(std::move(atLevel));
            
        }
        return ans;
    }

};