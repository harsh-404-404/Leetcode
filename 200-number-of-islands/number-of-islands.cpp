class Solution {
private:
    static constexpr std::array<std::array<int, 2>, 4> directions {{{0,-1}, {-1,0}, {0,1}, {1,0}}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<std::pair<int,int>> qu {}; 

        auto clear_island = [&](int i, int j)->void{
            qu.emplace(i,j);
            grid[i][j] = '0';

            while(!qu.empty()){
                auto [r, c] = qu.front();
                qu.pop();


                for(auto dir : directions){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nc >= 0 && nc < cols && nr >= 0 && nr < rows && grid[nr][nc] == '1'){
                        grid[nr][nc] = '0';
                        qu.emplace(nr,nc);
                    } 
                }
            }
            return;
        };

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == '1'){
                    clear_island(i,j);
                    ans++;
                }
            }
        }

        return ans;
    }
};