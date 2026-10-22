class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int feq[128] {};
        for(auto& row : board)
            for(char c : row) 
                feq[c]++;
        
        for(char c : word){
            if(feq[c] < 1) return false;
        }
        if (feq[word.back()] < feq[word.front()]) {
            reverse(word.begin(), word.end());
        }

        auto solve = [&](auto& self, int idx, int i, int j) {
            if (idx == word.size())
                return true;
            if (j > 0 && board[i][j - 1] == word[idx]) {
                if (idx == word.size() - 1)
                    return true;
                char temp = board[i][j];
                board[i][j] = '-';
                if (self(self, idx + 1, i, j - 1))
                    return true;
                board[i][j] = temp;
            }
            if (j < board[0].size() - 1 && board[i][j + 1] == word[idx]) {
                if (idx == word.size() - 1)
                    return true;
                char temp = board[i][j];
                board[i][j] = '-';
                if (self(self, idx + 1, i, j + 1))
                    return true;
                board[i][j] = temp;
            }
            if (i > 0 && board[i - 1][j] == word[idx]) {
                if (idx == word.size() - 1)
                    return true;
                char temp = board[i][j];
                board[i][j] = '-';
                if (self(self, idx + 1, i - 1, j))
                    return true;
                board[i][j] = temp;
            }
            if (i < board.size() - 1 && board[i + 1][j] == word[idx]) {
                if (idx == word.size() - 1)
                    return true;
                char temp = board[i][j];
                board[i][j] = '-';
                if (self(self, idx + 1, i + 1, j))
                    return true;
                board[i][j] = temp;
            }
            return false;
        };

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && solve(solve, 1, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};