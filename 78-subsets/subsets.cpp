class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> ans {};
        ans.reserve(1 << n);
        int final_permutation = 1 << n;
        for(int permutation = 0; permutation < final_permutation ;++permutation){
            std::vector<int> curr {};
            curr.reserve(__builtin_popcount(permutation));
            for(int j = 0; j < n; ++j){
                if(permutation & (1 << j)) curr.push_back(nums[j]);
            }
            ans.push_back(std::move(curr));
        }
        
        return ans;
    }
}; 