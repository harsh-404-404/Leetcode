class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> rank {};

        std::vector<int> ans {};
        ans.reserve(nums.size()- k + 1);

        int size = nums.size();
        for(int i = 0; i < size; ++i){

            if(!rank.empty() && rank.front() == i - k) rank.pop_front();

            while(!rank.empty() && nums[rank.back()] <= nums[i]) rank.pop_back();

            rank.push_back(i);

            if(i >= k - 1){
                ans.push_back(nums[rank.front()]);
            }
        }
        return ans;
    }
};
