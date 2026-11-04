class Solution {
public:
    int numDecodings(string s) {
        
        int prv1 = 1;
        int prv2 = 0;
        int prv = 0;

        for(int i = 0; i < s.size(); ++i){
            int curr = s[i] - '0';
            if(!curr){
                if(!prv2 || prv > 2) return 0;
                prv1 = prv2;
                prv2 = 0;
                continue;
            }
            if(prv > 1 && prv*10 + curr > 26){
                prv = curr;
                prv2 = prv1;
                continue;
            }
            int temp = prv1 + prv2;
            prv2 = prv1;
            prv1 = temp;
            prv = curr;
        }

        return prv1;

    }
};