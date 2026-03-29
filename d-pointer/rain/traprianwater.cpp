#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int countwater(int wall1 , int wall2 , vector<int>& height){
        int ans = 0;
        int bound = min(height[wall1] , height[wall2]);
        for(int i = 1; wall1 + i < wall2 ; i++){
            ans += (bound-height[wall1+i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        int water = 0;
        int wall1 = 0;
        while(wall1 + 1 < height.size()){
            for(int wall2 = wall1 + 1 ; wall2 < height.size() ; ++wall2){
                int tmpmax = height[wall1];
                if(tmpmax <= height[wall2] && (wall2 - wall1) == 1) break;
                //else if(tmpmax > height[wall2] && (wall2 - wall1) == 1 ) continue;
                else{
                    if(tmpmax > height[wall2]) continue;
                    water += countwater(wall1 , wall2 , height);
                    wall1 = wall2-1;
                    break;
                }
            }
            ++wall1;
        }
        return water;
    }
};

int main() {
    Solution sol;
    //vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> h2 = {4,2,3};
    // expected: 6, 9
    //printf("%d\n", sol.trap(h1));
    printf("%d\n", sol.trap(h2));
    return 0;
}