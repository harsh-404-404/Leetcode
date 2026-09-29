class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_set<char> set{};

        int b = 0;
        int e = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); ++i){
            if(!set.contains(s[i])){
                set.insert(s[i]);
                e++;
            }else{
                ans = std::max(ans, static_cast<int>(set.size()));
                char c = s[i];
                while(set.contains(c)) set.erase(s[b++]);
                set.insert(c);
            }
        }
        ans = std::max(ans, static_cast<int>(set.size()));

        return ans;
    }
};