class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char,int> map {};
        std::unordered_map<char,int> com_m {};
        for(auto c : s1) map[c]++;

        int b = 0;
        int e = s1.size() - 1;

        while(e < s2.size()){
            for(int i = b; i <= e; ++i) com_m[s2[i]]++;
            
            if(map == com_m) return true;

            com_m.clear();
            b++;e++;
        }
        return false;
    }
};