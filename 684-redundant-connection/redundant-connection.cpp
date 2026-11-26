class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        std::vector<int> ans (2);
        iota(parent.begin(), parent.end(), 0);

        auto get_parent = [&](this auto& self, int i) -> int {
            return (parent[i] == i) ? i : (parent[i] = self(parent[i]));
        };

        for(int i = 0; i < edges.size(); ++i){
            int prnt1 = get_parent(edges[i][0]);
            int prnt2 = get_parent(edges[i][1]);
            if(prnt1 == prnt2){
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }else{
                parent[prnt2] = prnt1;
            }

        }
        return ans;
    }
};