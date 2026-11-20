class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& values) {
        int row = values.size();
        int col = values[0].size();

        std::vector<std::vector<bool>> pw (row, std::vector<bool> (col, false));
        std::vector<std::vector<bool>> aw (row, std::vector<bool> (col, false));
        std::vector<std::vector<int>> ans {};
        ans.reserve(row*col);

        auto dfs = [&](auto& self,auto& water ,int prev_val, int i, int j)->void{
            if(i < 0 || i == row || j < 0 || j == col || values[i][j] < prev_val || water[i][j]) return;
            water[i][j] = true;
            int my_val = values[i][j];
            self(self,water,my_val,i+1, j);
            self(self,water,my_val,i-1, j);
            self(self,water,my_val,i,j+1);
            self(self,water,my_val,i, j-1);
            return;
        };

        for(int i = 0; i < col; ++i){
            dfs(dfs,pw,-1,0,i);
            dfs(dfs,aw,-1,row-1,col - 1 - i);
        } 
        for(int i = 0; i < row; ++i) {
            dfs(dfs,pw,-1,i,0);
            dfs(dfs,aw,-1,row - 1 - i,col-1);
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(pw[i][j] && aw[i][j]) ans.push_back({i,j});
            }
        }

        return ans;

    }
};