class Solution {
public:
    int countSubstrings(string s) {
        int ans {};

        auto solve = [&](int left, int right)->void{
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                ans++;
                left--,right++;
            }
        };

        for(int i = 0; i < s.size(); ++i){
            solve(i, i);
            solve(i, i+1);
        }

        return ans;
    }
};