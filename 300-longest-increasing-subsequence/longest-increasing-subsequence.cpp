class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp (nums.size() + 1, INT_MIN);
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i){
            int curr = nums[i];
            if(curr > dp[max_len]){
                dp[++max_len] = curr;
            }
            else{
                int front = 0;
                int back = max_len;
                while(front < back){
                    int mid = front + (back - front)/2;
                    
                    if(dp[mid] >= curr) back = mid;           
                    else front = mid + 1;
                }
                dp[front] = curr;
            }
        }
        return max_len;
    }
};