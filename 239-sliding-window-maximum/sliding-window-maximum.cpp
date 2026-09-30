class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> rank {};

        std::vector<int> ans {};
        ans.reserve(nums.size()- k + 1);

        rank.push_front(0);
        for(int i = 1; i < k; ++i){
            int value = nums[i];
            if(value >= nums[rank.back()]){
                rank.push_back(i);
            }else{
                while(value >= nums[rank.front()]) rank.pop_front();
                rank.push_front(i);
            }
        }
        ans.push_back(nums[rank.back()]);
        int b = 1;
        int e = k;
        for(;e < nums.size(); ++e,++b){
            int value = nums[e];
            if(value >= nums[rank.back()]){
                rank.push_back(e);
            }else{
                while(value >= nums[rank.front()]) rank.pop_front();
                rank.push_front(e);
            }
            while(rank.back() < b) rank.pop_back();
            ans.push_back(nums[rank.back()]);
        }
        return ans;

    }
};
