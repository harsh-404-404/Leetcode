class Solution {
private:
    std::vector<std::vector<int>> ans {};
    std::vector<int> path {};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
    
    void helper(std::vector<int>& nums, int i){
        if(i == nums.size()){
            ans.push_back(path);
            return;
        }
        helper(nums, i+1);
        path.push_back(nums[i]);
        helper(nums, i+1);
        path.pop_back();
    }
}; 