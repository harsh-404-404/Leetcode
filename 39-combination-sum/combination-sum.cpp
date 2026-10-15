class Solution {
private:
    std::vector<std::vector<int>> ans {};
    std::vector<int> current_one {};
    int curr = 0;
    int val;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        val = target;
        helper(candidates, 0);
        return ans;
    }

    void helper(std::vector<int>& candidates, int i) {

        if (curr == val) {
            ans.push_back(current_one);
            return;
        }

        if (curr > val || i >= (int)candidates.size()) return;

        current_one.push_back(candidates[i]);
        curr += candidates[i];
        helper(candidates, i);

        curr -= candidates[i];
        current_one.pop_back();
        
        helper(candidates, i + 1);
    }
};