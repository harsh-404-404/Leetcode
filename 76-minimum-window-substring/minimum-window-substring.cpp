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

        int AnsStart = 0;
        int BestLength = INT_MAX;
        for(int e = 0; e < ssize; ++e){
            char c = s[e];

            if(array[c] > 0) missing--; 
            array[c]--;

            while(missing == 0){
                if(e - b + 1 < BestLength){
                    AnsStart = b;
                    BestLength = e - b + 1;
                }
                if(++array[s[b++]] > 0) missing++;
            }
            
        }
        if(BestLength == INT_MAX) return "";
        return s.substr(AnsStart,BestLength);

    }
};
