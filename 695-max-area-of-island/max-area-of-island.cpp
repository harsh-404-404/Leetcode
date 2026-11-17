class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        auto solve = [&](auto& self, int i, int j){
            if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) return 0;
            grid[i][j] = 0;

            return 1 + self(self,i+1,j) + self(self,i-1,j) + self(self,i,j+1) + self(self,i,j-1);
        };

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){
                    ans = std::max(ans, solve(solve, i, j));
                }
            }
        }
        return ans;
    }
};