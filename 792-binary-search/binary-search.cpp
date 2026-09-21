class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int heigh = nums.size() - 1;
        while(low <= heigh){
            int mid = low + (heigh - low) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] < target ) low = mid + 1;
            
            else heigh = mid - 1;

        }
        return -1;
    }
};