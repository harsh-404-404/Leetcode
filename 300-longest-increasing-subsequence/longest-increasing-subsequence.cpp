class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp (nums.size(), 0);

        for(int i = nums.size() - 1; i >= 0; --i){
            int curr = nums[i];
            int j = i + 1;
            int max = 0;
            while(j < nums.size()){
                if(nums[j] > curr) max = std::max(dp[j] + 1,max);
                j++;
            }
            dp[i] = max;
        }
        return *std::max_element(dp.begin(), dp.end()) + 1;
    }
};