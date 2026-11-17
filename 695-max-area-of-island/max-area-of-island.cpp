class Solution {
    static constexpr int rd[] = {0, -1, 0, 1};
    static constexpr int cd[] = {-1, 0, 1, 0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        std::queue<std::pair<int,int>> qu{};

        int row = grid.size();
        int col = grid[0].size();

        auto bfs = [&](int i, int j) -> int {
            int size = 1;
            qu.emplace(i,j);
            grid[i][j] = 0;

            while(!qu.empty()){
                auto [r, c] = qu.front();
                qu.pop();

                for(int k = 0; k < 4; ++k){
                    int nr = r + rd[k];
                    int nc = c + cd[k];

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1){
                        grid[nr][nc] = 0;
                        qu.emplace(nr,nc);
                        size++;
                    }
                }
                ans = std::max(ans, size);
            }
            return ans;
        };

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){
                    bfs(i,j);
                }
            }
        }
        return ans;
    }
};