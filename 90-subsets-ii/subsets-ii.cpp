class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(),nums.end());

        std::vector<std::vector<int>> ans {};
        std::vector<int> curr {};
        curr.reserve(n);
        ans.reserve(1 << n);

        int final_permutation = 1 << n;
        for(int permutation = 0; permutation < final_permutation; ++permutation){
            curr.clear();
            for(int i = 0; i < n; ++i){
                if(permutation & (1 << i)){
                    if(i > 0 && (nums[i] == nums[i-1]) && !(permutation & (1 << (i-1)))){
                        curr.clear();
                        break;
                    }
                    curr.push_back(nums[i]);
                }
            }
            if(curr.size() != 0){
                ans.push_back(std::move(curr));
            }
        }
        ans.emplace_back();
        return ans;
    }
};