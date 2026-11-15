class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        auto clear_island = [&](auto& self, int i, int j){
            if(i >= rows || j >= cols || i < 0 || j < 0 || grid[i][j] == '0') return;
            grid[i][j] = '0';
            self(self,i,j+1); 
            self(self,i,j-1);
            self(self,i+1,j);
            self(self,i-1,j);
            return;
        };

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == '1'){
                    clear_island(clear_island,i,j);
                    ans++;
                }
            }
        }

        return ans;
    }
};