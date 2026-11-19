class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<int> curr,next;

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 2){
                    grid[i][j] = 0;
                    curr.push_back(i*col + j);
                }
            }
        }
        int minutes = -1;
        while(!curr.empty()){
            minutes++;
            next.clear();
            for(int idx : curr){
                int i = idx / col;
                int j = idx % col;
                if(i > 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 0;
                    next.push_back((i-1)*col + j);
                }
                if(j > 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 0;
                    next.push_back(i*col + (j-1));
                }
                if(i < row - 1 && grid[i+1][j] == 1){
                    grid[i+1][j] = 0;
                    next.push_back((i+1)*col + j);
                }
                if(j < col - 1 && grid[i][j+1] == 1){
                    grid[i][j+1] = 0;
                    next.push_back(i*col + (j+1));
                }
            }
            std::swap(curr,next);
        }


        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }  
            }
        }
        if(minutes == -1) return 0;
        return minutes;
    }
};