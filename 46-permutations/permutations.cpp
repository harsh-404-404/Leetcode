class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<int> hash (nums.size(), 0);
        std::vector<int> curr {};
        std::vector<std::vector<int>> ans {};

        auto solve = [&](auto& self) ->void{
            if(curr.size() == nums.size()){
                ans.push_back(curr);
                return;
            }
            for(int i = 0; i < nums.size(); ++i){
                if(hash[i]) continue;
                curr.push_back(nums[i]);
                hash[i] = 1;
                self(self);
                hash[i] = 0;
                curr.pop_back();
            }
        };
        solve(solve);
        return ans;
    }
};