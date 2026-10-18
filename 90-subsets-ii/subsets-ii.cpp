class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> ans {};
        std::vector<int> curr {};
        std::sort(nums.begin(),nums.end());

        auto solve = [&](auto& self, int start)-> void {
            ans.push_back(curr);
            
            for(int i = start; i < nums.size(); ++i){
                if(i > start && nums[i] == nums[i-1]){
                    continue;
                }
                
                curr.push_back(nums[i]);
                self(self,i+1);
                curr.pop_back();
            }
        };
        solve(solve,0);

        return ans;
    }
};