class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unsigned int col = 0, left_dia = 0, right_dia = 0;
        std::vector<std::vector<std::string>> ans;
        
        std::vector<std::string> board(n, std::string(n, '.'));

        auto solve = [&](auto& self, int row) -> void {
            if (row >= n) {
                ans.push_back(board);
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (col & (1U << j) || 
                    left_dia & (1U << (row + j)) ||
                    right_dia & (1U << (row - j + n - 1))) {
                        continue;
                }
                
                // Set state
                col |= (1U << j);
                left_dia |= (1U << (row + j));
                right_dia |= (1U << (row - j + n - 1));
                board[row][j] = 'Q'; 

                self(self, row + 1);

                // Revert state
                board[row][j] = '.';
                col &= ~(1U << j);   
                left_dia &= ~(1U << (row + j));
                right_dia &= ~(1U << (row - j + n - 1));
            }
        };
        
        solve(solve, 0);
        return ans;
    }
};