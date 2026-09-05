class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        
        int row[9] {};
        int col[9] {};
        int box[9] {};

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                char c {board[i][j]};

                if(c == '.') continue;
            
                int bindex = { (i/3)*3 + (j/3) };
                int bits = 1 << (c - '1');
                if(row[i] & bits || col[j] & bits|| box[bindex] & bits){
                    return false;
                }
                row[i] |= bits;
                col[j] |= bits;
                box[bindex] |= bits;
            }
        }
        return true;
    }
};