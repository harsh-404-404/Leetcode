class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        std::unordered_set<std::string> word(wordList.begin(), wordList.end());

        if(!word.contains(endWord)) return 0;

        std::queue<std::string> qu {};
        qu.push(beginWord);
        word.erase(beginWord);

        int ans = 0;
        while(qu.size()){
            int qusize = qu.size();
            
            for(int _ = 0; _ < qusize; ++_){
                std::string curr = qu.front();
                qu.pop();
                
                for(int i = 0; i < curr.size(); ++i){
                    char original = curr[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        if(c == original) continue;
                        curr[i] = c;
                        if(curr == endWord) return ans + 2;
                        if(word.contains(curr)){
                            qu.push(curr);
                            word.erase(curr);
                        } 
                    }
                    curr[i] = original;
                }
            }
            ans++;
        }
        return 0;
}

};