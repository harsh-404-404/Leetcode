class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans {};
        std::vector<int> curr {};
        std::sort(candidates.begin(),candidates.end());

        auto solve = [&](auto& self, int remaining, int idx) -> void {
            if(remaining == 0){
                ans.push_back(curr);
                return;
            }
            for(int i = idx; i < candidates.size(); ++i){
                if(i > idx && candidates[i] == candidates[i - 1]) continue;
                if(candidates[i] > remaining) return;

                curr.push_back(candidates[i]);
                self(self,remaining - candidates[i], i + 1);
                curr.pop_back();
            }
        };
        solve(solve, target, 0);
        return ans;
    }
};