class Solution {
private:
    std::vector<std::vector<int>> ans {};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0, {});
        return ans;
    }
    
    void helper(std::vector<int>& nums, int i,std::vector<int> path){
        if(i == nums.size()){
            ans.push_back(std::move(path));
            return;
        }
        helper(nums, i+1, path);
        path.push_back(nums[i]);
        helper(nums, i+1, path);
    }
}; 