class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> ans {};
        std::vector<std::string> curr {};
        
        auto solve = [&](auto& self, std::string_view sv) -> void{
            if(!sv.size()){
                ans.push_back(curr);
                return;
            }

            for(int i = 0; i < sv.size(); ++i){
                if(isPalin(sv.substr(0,i+1))){
                    curr.emplace_back(sv.substr(0,i+1));
                    self(self,sv.substr(i+1));
                    curr.pop_back();
                }
            }

            return;
        };

        solve(solve,s);
        return ans;
    }

    bool isPalin(std::string_view s){
        int b = 0;
        int e = s.size() - 1;
        while(b < e){
            if(s[b] != s[e]) return false;
            b++,e--;
        }
        return true;
    }
};