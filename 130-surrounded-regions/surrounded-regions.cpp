class Solution {
private: 
    static constexpr int arr[][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        auto dfs = [&](auto& self, int i, int j)->void{
            board[i][j] = '#';

            for(auto [r, c] : arr){
                int nr = r + i;
                int nc = c + j;
                if(nr < 0 || nc < 0 || nr >= row || nc >= col || board[nr][nc] != 'O') continue;
                self(self, nr, nc);
            }
            return;
        };

        for(int i = 0; i < row; ++i){
            if(board[i][0] == 'O') dfs(dfs,i,0);
            if(board[i][col - 1] == 'O') dfs(dfs, i, col-1);
        }
        for(int i = 0; i < col; ++i){
            if(board[0][i] == 'O') dfs(dfs,0,i);
            if(board[row-1][i] == 'O') dfs(dfs, row-1, i);
        }
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;
    }
};