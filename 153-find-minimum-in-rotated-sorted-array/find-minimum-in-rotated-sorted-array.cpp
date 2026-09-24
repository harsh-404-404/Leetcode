class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while(s < e){
            int m = s + (e - s)/2;

            if(nums[s] > nums[e] && s + 1 == e) return nums[e]; 
            if(nums[m] < nums[e]) e = m;

            else s = m;
        }
        return nums[s];
    }
};