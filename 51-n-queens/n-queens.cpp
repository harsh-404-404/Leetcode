class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unsigned int col = 0;
        unsigned int left_dia = 0;
        unsigned int right_dia = 0;
        std::vector<std::vector<std::string>> ans{};
        std::vector<int> curr (n, 0);

        auto solve = [&](auto& self, int row) -> void {
            if (row >= n) {
                std::vector<std::string> board (n, std::string(n, '.'));
                for(int i = 0; i < n; ++i){
                    board[i][curr[i]] = 'Q';
                }
                ans.push_back(std::move(board));
                return;
            }

            // try placing the queen on current row
            for (int j = 0; j < n; ++j) {
                if (col & (1U << j) || 
                    left_dia & (1U << (row + j)) ||
                    right_dia & (1U << (row - j + n - 1))) {
                        continue;
                }
                col |= (1U << j);
                left_dia |= (1U << (row + j));
                right_dia |= (1U << (row - j + n - 1));

                curr[row] = j;
                self(self, row + 1);
                curr[row] = 0;

                col &= ~(1 << j);
                left_dia &= ~(1 << (row + j));
                right_dia &= ~(1 << (row - j + n - 1));
            }
            return;
        };
        solve(solve,0);
        return ans;
    }
};