class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set set (wordDict.begin(),wordDict.end());
        
        std::vector<int> dp (s.size(), -1);

        auto solve = [&](auto& self, int first) -> bool{
            if(dp[first] == 1) return true;
            if(dp[first] == 0) return false;

            for(int second = first; second < s.size(); ++second){
                if(set.contains(s.substr(first,second - first + 1))){
                    if(second == s.size() - 1 || self(self, second + 1)){
                        dp[first] = true;
                        return true;
                    }
                }
            }
            dp[first] = 0;
            return false;
        };

        return solve(solve, 0);

    }
};