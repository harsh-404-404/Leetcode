class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ans {};
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while(k > j){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    ans.emplace_back(std::initializer_list<int>{nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && k > j) j++;    
                }
            }
        }
        return ans;
    }
};