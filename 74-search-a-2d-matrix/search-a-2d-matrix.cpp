class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low = 0;
        int heigh = (matrix.size() * matrix[0].size()) - 1;
        while(low <= heigh){
            int mid = low + (heigh - low) / 2;

            int i = mid / matrix[0].size();
            int j = mid % matrix[0].size();
            if(matrix[i][j] == target) return true;

            if(matrix[i][j] < target ) low = mid + 1;
            
            else heigh = mid - 1;
        }
        return false;

    }
};