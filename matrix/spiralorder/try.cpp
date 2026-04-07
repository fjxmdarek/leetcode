class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int times = 0;
        ans.reserve(m * n);
        while(m != 0 || n != 0){
            for(int i = 0 ; i < n ; ++i) ans.push_back(matrix[times][times+i]);
            if(!(--m)) break;
            for(int i = 0 ; i < m ; ++i) ans.push_back(matrix[times+1+i][times+n-1]);
            if(!(--n)) break;
            for(int i = 0 ; i < n ; ++i) ans.push_back(matrix[times+m][times+n-1-i]);
            if(!(--m)) break;
            for(int i = 0 ; i < m ; ++i) ans.push_back(matrix[times+m-i][times]);
            if(!(--n)) break;
            ++times;
        }
        return ans;
    }
};