class Solution {
private:
    std::vector<std::vector<int>> ans {};
    std::vector<int> current_one {};
    int curr = 0;
    int val;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        val = target;
        std::sort(candidates.begin(),candidates.end());
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

        helper(candidates, i+1);

        curr -= candidates[i];
        current_one.pop_back();

        while (i + 1 < (int)candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        helper(candidates, i+1);
    }
};