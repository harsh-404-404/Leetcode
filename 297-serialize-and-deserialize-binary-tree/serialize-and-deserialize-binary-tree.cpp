/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        if(!root) return "";

        std::string ans {};
        std::queue<TreeNode*> qu {};

        qu.push(root);

        while(qu.size()){
            int n = qu.size();
            for(int i = 0; i < n; ++i){
                auto x =  qu.front();
                qu.pop();

                if(!x){
                  ans.append("#,");
                  continue;  
                } 
                ans.append(std::to_string(x->val)).append(",");
                qu.push(x->left);
                qu.push(x->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int i = 0;
        int k = i;
        while(data[i++] != ','){}

        TreeNode* root = new TreeNode{std::stoi(data.substr(k,i-k-1))};
        std::queue<TreeNode*> qu {};
        qu.push(root);
        

        while(qu.size()){
            int n = qu.size();
            for(int j = 0; j < n; ++j){
                TreeNode* x = qu.front();
                
                if(data[i] != '#') {
                    k = i;
                    while(data[i++] != ','){}
                    x->left = new TreeNode{std::stoi(data.substr(k,i-k-1))};
                    qu.push(x->left);
                }else{
                    i += 2;
                }
                if(data[i] != '#'){
                    k = i;
                    while(data[i++] != ','){}
                    x->right = new TreeNode{std::stoi(data.substr(k,i-k-1))};
                    qu.push(x->right);
                }else{
                    i += 2;
                }
                qu.pop();
                
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));