class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int times = 0;
        int n ;
        vector<int> tmp;
        while((n = matrix.size()- times*2) > 1) {
            tmp.resize(n);
            for(int i = 0 ; i < n ; i++) tmp[i] = matrix[n+times-1-i][times];
            for(int i = 0 ; i < n ; i++) matrix[times+i][times] = matrix[n+times-1][times+i];
            for(int i = 0 ; i < n ; i++) matrix[n+times-1][times+i] = matrix[n+times-1-i][n+times-1];
            for(int i = 0 ; i < n ; i++) matrix[n+times-1-i][n+times-1] = matrix[times][n+times-1-i];
            for(int i = 0 ; i < n ; i++) matrix[times][times+i] = tmp[i];
            ++times; 
        }
    }
}; 