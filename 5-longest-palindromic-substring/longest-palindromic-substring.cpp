class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        std::string_view sv {};
        for(int i = 0; i < s.size(); ++i){
            int left = i;
            int right = i;
            if(right + 1 < s.size() && s[left] == s[right + 1]){
                right += 1;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    left--,right++;
                }
                if(sv.size() < right - left - 1){
                    sv = std::string_view(s).substr(left+1,right - left - 1);
                }
            }
            left = i;
            right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--,right++;
            }
            if(sv.size() < right - left - 1){
                sv = std::string_view(s).substr(left+1,right - left - 1);
            }
        }
        return std::string(sv);
    }
};