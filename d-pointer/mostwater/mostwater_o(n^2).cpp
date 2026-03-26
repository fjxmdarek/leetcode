class Solution {
    public:
    int maxArea(vector<int>& height){
        int maxwater = 0;
        for(int i=0; i<height.size() ; i++){
            for(int j=i+1 ; j<height.size() ; j++){
                maxwater = max(min(height[i],height[j])*(j-i) , maxwater);
            }
        }
        return maxwater;
    }
};