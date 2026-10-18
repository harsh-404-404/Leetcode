class Solution {
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> curr;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        helper(candidates,  target, 0);
        return ans;
    }

    void helper(vector<int>& candidates, int remaining,int start){
        if(remaining == 0){
            ans.push_back(curr);
            return;
        }
        for(int j = start; j < candidates.size(); ++j){
            int val = candidates[j];
            if(val > remaining) break;
            curr.push_back(val);
            helper(candidates, remaining - val, j);
            curr.pop_back();
        }
    }
};
