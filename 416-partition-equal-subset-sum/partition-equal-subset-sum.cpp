class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1) return !nums[0];
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2) return false;

        int target = sum / 2;
        std::vector<bool> dp (target+1, false);
        dp[0] = true;

        for(int j = 0; j < nums.size(); ++j){
            for(int i = target; i >= nums[j]; i--){
                dp[i] = dp[i] || dp[i - nums[j]];
            }
        }
        
        return dp[target];

    
    }
};