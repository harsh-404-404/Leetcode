class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> ans {};
        std::vector<int> curr {};
        curr.reserve(n);
        ans.reserve( 1 << n);

        auto solve = [&](auto& self, int start)-> void{
            ans.push_back(curr);
            for(int i = start; i < n; ++i){
                curr.push_back(nums[i]);
                self(self,i+1);
                curr.pop_back();
            }
        };
        solve(solve,0);
        return ans;

    }
}; 