static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[nums[0]];

        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }

        tortoise = 0;
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return tortoise;
    }
};