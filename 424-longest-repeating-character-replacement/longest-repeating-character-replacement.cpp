class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> array (27,0);
        int ans = 0;
        int max_feq = 0;
        int b = 0;
        for(int e = 0; e < s.size(); ++e){
            max_feq = std::max(max_feq, ++array[s[e] - 'A']);

            while((e - b + 1) - max_feq > k) array[s[b++] - 'A']--;

            ans = std::max(ans, e - b + 1);
        }
        return ans;
    }
};