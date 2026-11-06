class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int min_prev = nums[0];
        int max_prev = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            int curr_max = std::max({min_prev*nums[i],max_prev*nums[i],nums[i]});
            int curr_min = std::min({min_prev*nums[i],max_prev*nums[i],nums[i]});
            max_prev = curr_max;
            min_prev = curr_min;
            max = std::max(max,max_prev);
        }
        return max;


    }
};