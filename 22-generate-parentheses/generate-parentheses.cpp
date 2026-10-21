class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans {};
        std::string curr {};
        int s = n;
        int c = 0;

        auto solve = [&](auto& self)->void{
            if(s == 0 && c == 0){
                ans.push_back(curr);
            }

            if(s != 0){        
                curr.push_back('(');
                s--,c++;
                self(self);
                curr.pop_back();
                s++,c--;
            }
            
            if(c != 0){
                curr.push_back(')');
                c--;
                self(self);
                curr.pop_back();
                c++;
            }
            return;
        };
        solve(solve);
        return ans;
        
    }
};