class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;

        auto pt1 = s.begin();
        auto pt2 = s.end() - 1;

        while(pt1 < pt2){
            if(!std::isalnum(*pt1)){
                pt1++;
            }
            else if(!std::isalnum(*pt2)){
                pt2--;
            }
            else{
                if(std::tolower(*pt1) != std::tolower(*pt2)){
                    return false;
                }
                pt1++;
                pt2--;
            } 

        }
        return true;
    }
};