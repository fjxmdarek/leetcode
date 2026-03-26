class Solution {
    public:
    int maxArea(vector<int>& height){
        int maxwater = 0;
        int i=0 , j=height.size()-1;
        while(i != j){
            maxwater = max(maxwater , (j-i) * min(height[i] , height[j]));
            if(height[i] > height[j]){
                --j;
            }else{
                ++i;
            }
        }
        return maxwater;
    }
};