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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int,int> index {};
        for(int i = 0; i < inorder.size(); ++i) index[inorder[i]] = i;
        return build(0,index,preorder,inorder);
    }

    TreeNode* build(int offset,std::unordered_map<int,int>& index,std::span<int> preorder, std::span<int> inorder) {
        if(!preorder.size() || !inorder.size()) return nullptr;
        if(preorder.size() == 1) return new TreeNode{preorder[0],nullptr,nullptr};

        int val = preorder[0];
        int mid = index[val] - offset;

        TreeNode* left = build(
            offset,
            index,
            preorder.subspan(1,mid),
            inorder.subspan(0,mid)
            );
        TreeNode* right = build(
            offset + mid + 1,
            index,
            preorder.subspan(mid + 1),
            inorder.subspan(mid + 1)
        );

        return new TreeNode{val,left,right};
    }
};