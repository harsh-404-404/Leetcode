class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unsigned int col = 0;
        unsigned int left_dia = 0;
        unsigned int right_dia = 0;
        std::vector<std::vector<std::string>> ans{};
        std::vector<std::string> curr(n, std::string(n, '.'));

        auto solve = [&](auto& self, int row) -> void {
            if (row >= n) {
                ans.push_back(curr);
                return;
            }

            // try placing the queen on current row
            for (int j = 0; j < n; ++j) {
                if (col & (1 << j) || 
                    left_dia & (1 << (row + j)) ||
                    right_dia & (1 << (row - j + n - 1))) {
                        continue;
                }
                col |= (1 << j);
                left_dia |= (1 << (row + j));
                right_dia |= (1 << (row - j + n - 1));

                curr[row][j] = 'Q';
                self(self, row + 1);
                curr[row][j] = '.';

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