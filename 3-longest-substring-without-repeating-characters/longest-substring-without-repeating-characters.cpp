class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::vector<int> array(256,-1);

        int b = 0;
        int e = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(array[c] == -1){
                array[c] = i;
            }else if(array[c] < b){
                array[c] = i;
            }
            else{
                ans = std::max(ans, e - b);
                b = array[c] + 1;
                array[c] = i;
            }
            e++;
        }
        ans = std::max(ans, e - b);

        return ans;
    }
};