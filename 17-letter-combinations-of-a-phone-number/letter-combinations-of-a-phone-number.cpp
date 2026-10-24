class Solution {
private:
    std::array<std::string,9> hash {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> ans {};
        std::string curr {};
        std::vector<int> idigits {};

        idigits.reserve(digits.size());
        for(char c : digits) idigits.push_back(c - '0');

        auto solve = [&](auto& self,int idx) -> void {

            if(idx == idigits.size()){
                ans.push_back(curr);
                return;
            }

            std::string_view st = hash[idigits[idx] - 1];

            for(int i = 0; i < st.size(); ++i){
                curr.push_back(st[i]);
                self(self, idx+1);
                curr.pop_back();
            }

            return;
        };

        solve(solve,0);
        return ans;
    }
};