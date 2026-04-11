class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int times = 0;
        int n = matrix.size();
        while ((n = matrix.size()- times*2) > 1) {
            for (int i = 0; i < n - 1; i++) {
                int tmp = matrix[times][times + i];
                matrix[times][times + i]                     = matrix[n + times - 1 - i][times];
                matrix[n + times - 1 - i][times]             = matrix[n + times - 1][n + times - 1 - i];
                matrix[n + times - 1][n + times - 1 - i]     = matrix[times + i][n + times - 1];
                matrix[times + i][n + times - 1]             = tmp;
            }
            ++times;
        }
    }
};
