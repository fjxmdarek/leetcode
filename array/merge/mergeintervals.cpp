#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin() , intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 0 ; i < intervals.size() - 1; i++){
            if(right < intervals[i+1][0]) {
                ans.push_back({left , right});
                left = intervals[i+1][0];
            }
            right = max(right , intervals[i+1][1]);
        }
        ans.push_back({left , right});
        return ans;
    }
};

int main() {
    vector<vector<int>> intervals = {{5,6},{1,2},{2,4},{5,5},{5,5},{3,3}};
    Solution sol;
    vector<vector<int>> ans = sol.merge(intervals);
    for (auto& v : ans)
        cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    return 0;
}