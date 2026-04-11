class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix , int target) {
        int i = 0;
        while(matrix[i][i] < target && (i+1) <= matrix[0].size() && (i+1) <= matrix.size()) {
            if(i == matrix[0].size()-1 || i == matrix.size()-1 ) return 0;
            else ++i;
        }
        int m = i+1 , n = i+1;
        while(((--m) >= 0 && (--n) >= 0 && (matrix[m][i] >= target || matrix[i][n] >= target))) {
            if(matrix[m][i] == target || matrix[i][n] == target) return 1;
        }
        return 0;
    }
};