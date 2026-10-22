class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int k = word.size();

        auto solve = [&](auto& self, int idx, int i, int j) {
            if(idx == k) return true;

            if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx]) 
                return false;

            char temp = board[i][j];
            board[i][j] = '-';

            bool ans = (self(self, idx + 1, i, j-1) ||
                        self(self, idx + 1, i, j+1) ||
                        self(self, idx + 1, i-1, j) ||
                        self(self, idx + 1, i+1, j));

            board[i][j] = temp;
            return ans;
        };


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (solve(solve, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};