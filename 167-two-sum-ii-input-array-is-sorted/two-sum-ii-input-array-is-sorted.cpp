class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> ans {0, static_cast<int>(numbers.size()- 1)};

        while(ans[0] < ans[1]){
            if(numbers[ans[0]] + numbers[ans[1]] == target){
                ans[0]++;
                ans[1]++;
                return ans;
            }else if(numbers[ans[0]] + numbers[ans[1]] < target){
                ans[0]++;
            }else{
                ans[1]--;
            }
        }
        ans[0]++;
        ans[1]++;
        return ans;
    }
};