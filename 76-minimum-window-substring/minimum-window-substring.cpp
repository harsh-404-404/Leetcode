class Solution {
public:


    string minWindow(string s, string t) {
        int tsize = t.size();
        int ssize = s.size();

        if(ssize < tsize)return "";

        std::array<int,129> array {}; 
        for(char c : t) array[c]++;

        int b = 0;
        int missing = tsize;

        std::pair<int, int> ans {0,INT_MAX};
        for(int e = 0; e < ssize; ++e){

            if(array[s[e]] > 0) missing--; 
            array[s[e]]--;

            if(missing != 0) continue;

            while(missing <= 0){
                ans = (ans.second - ans.first > e - b) ? std::make_pair(b,e) : ans;
                if(++array[s[b++]] > 0) missing++;
            }
            
        }
        if(ans.second == INT_MAX) return "";
        return s.substr(ans.first,(ans.second - ans.first) + 1);

    }
};
