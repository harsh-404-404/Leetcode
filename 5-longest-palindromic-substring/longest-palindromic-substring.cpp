class Solution {
public:
    string longestPalindrome(string s) {

        std::string_view sv {};

        auto solve = [&](int left, int right)->void{
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--,right++;
            }
            if(sv.size() < right - left - 1){
                sv = std::string_view(s).substr(left+1,right - left - 1);
            }
        };
        for(int i = 0; i < s.size(); ++i){
            solve(i,i);
            solve(i,i+1);
        }
        return std::string(sv);
    }
};