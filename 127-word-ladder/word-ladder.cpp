class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        std::queue<int> qu {};
        std::vector<bool> visited (wordList.size(), false);
        for(int i = 0; i < wordList.size();++i){
            if(differ_by_one(beginWord,wordList[i])){
                if(wordList[i] == endWord) return 2;
                qu.push(i);
                visited[i] = true;
            }
        }

        int ans = 1;
        while(qu.size()){
            int qusize = qu.size();
            for(int i = 0; i < qusize; ++i){
                for(int j = 0; j < wordList.size(); ++j){
                    if(!visited[j] && differ_by_one(wordList[j],wordList[qu.front()])){
                        if(endWord == wordList[j]) return ans + 2;
                        qu.push(j);
                        visited[j] = true;
                    }
                }
                qu.pop();
            }
            ans++;
        }
        return 0;
    }

    bool differ_by_one(std::string_view first, std::string_view second){
        if(first.size() != second.size()){ return false; }
        int differ = 0;
        for(int i = 0; i < first.size(); ++i){
            if(first[i] != second[i]){
                differ++;
                if(differ > 1) return false;
            }
        }
        return true;
    }
};