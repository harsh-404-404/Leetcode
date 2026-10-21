class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans {};
        std::string curr (2*n, ' ');
        auto solve = [&](auto& self,int o,int c,int idx) -> void{
            if(c == n){
                ans.push_back(curr);
                return;
            }

            if(o < n){        
                curr[idx] = '(';
                self(self, o+1, c, idx+1);
            }
            
            if(o > c){
                curr[idx] = ')';
                self(self, o, c+1, idx+1);
            }
            return;
        };
        solve(solve, 0, 0, 0);
        return ans;
        
    }
};