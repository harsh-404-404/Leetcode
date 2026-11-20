class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& values) {
        int row = values.size();
        int col = values[0].size();

        std::vector<std::vector<int>> pw (row, std::vector<int> (col, 0));
        
        auto pacific = [&](auto& self,int prev_val, int i, int j)->void{
            if(i < 0 || i == row || j < 0 || j == col || values[i][j] < prev_val || pw[i][j]) return;
            pw[i][j] = 1;
            int my_val = values[i][j];
            self(self, my_val,i+1, j);
            self(self, my_val,i-1, j);
            self(self, my_val,i,j+1);
            self(self, my_val,i, j-1);
            return;
        };

        for(int i = 0; i < col; ++i){
            pacific(pacific,-1,0,i);
        } 
        for(int i = 0; i < row; ++i) {
            pacific(pacific,-1,i,0);
        }    

        std::vector<std::vector<int>> aw (row, std::vector<int> (col, 0));
        auto atlantic = [&](auto& self,int prev_val, int i, int j)->void{
            if(i < 0 || i == row || j < 0 || j == col || values[i][j] < prev_val || aw[i][j]) return;
            aw[i][j] = 1;
            int my_val = values[i][j];
            self(self, my_val,i+1, j);
            self(self, my_val,i-1, j);
            self(self, my_val,i,j+1);
            self(self, my_val,i, j-1);
            return;
        };

        for(int i = col - 1; i >= 0; --i){
            atlantic(atlantic,-1,row-1,i);
        } 
        for(int i = row - 1; i >= 0; --i) {
            atlantic(atlantic,-1,i,col-1);
        }    

        std::vector<std::vector<int>> ans {};
        ans.reserve(row*col);
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(pw[i][j] && aw[i][j]) ans.push_back({i,j});
            }
        }
        return ans;

    }
};