class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0],nums[1]);
        
        int prev1 = 0;
        int prev2 = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            int temp = std::max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }
        int f = prev1;
        
        prev1 = 0;
        prev2 = 0;
        for(int i = 1; i < nums.size(); ++i){
            int temp = std::max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }

        return std::max(f, prev1);
    }
};