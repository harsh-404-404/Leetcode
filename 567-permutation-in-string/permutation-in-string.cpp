class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        std::array<int,27> arr {};
        for(auto c : s1) arr[c - 'a']++;

        for(int i  = 0; i < s1.size(); ++i) arr[s2[i] - 'a']--;
        if(all_zero(arr)) return true;

        int s = 0;
        int e = s1.size() - 1;
        while(e < s2.size() - 1){
            arr[s2[s++] - 'a']++;
            arr[s2[++e] - 'a']--;
            if(all_zero(arr)) return true;
        }
        return false;
    }

    bool all_zero(std::array<int, 27>& a){
        for(int i = 0; i < 27; ++i){
            if(a[i] != 0){
                return false;
            }
        }
        return true;
    }
};