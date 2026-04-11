class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix , int target) {
        int m = matrix.size()-1 , n = matrix[0].size()-1;
        int i;
        for(i = 0 ; i < min(m,n) ; i++) {
            if(matrix[m - i][n - i] == target) return 1;
            else if(matrix[m-i][n-i] < target) break;
        }
        if(matrix[m - i][n - i] == target) return 1;
        /*
        if(i == min(m,n)) return 0;
        for(int j = 1 ; j < i ; ++j) {
            if(matrix[m-i][n-i+j] == target || matrix[m-i+j][n-i] == target) return 1;
        }*/
        int row = m-i , column = n-i , j = 0 ;
        while(row - j > 0){
            ++j;
            if(matrix[row-j][column] == target) return 1;
        }
        j = 0;
        while(column - j > 0){
            ++j;
            if(matrix[row][column-j] == target) return 1;
        }
        return 0;
    }
};