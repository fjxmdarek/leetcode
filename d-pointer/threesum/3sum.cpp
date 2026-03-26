class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int first = 0 ; first < n ; ++first){
            if(nums[first] > 0) break;
            if(first > 0 && nums[first] == nums[first-1]) continue;
            int traget = -nums[first];
            int third = n-1;
            for(int second = first+1 ; second < n ; ++second){
                if(second > first+1 && nums[second] == nums[second-1]) continue;
                while(third > second && nums[second] + nums[third] > traget){
                    --third;
                }
                if(second == third) break;
                if(nums[second] + nums[third] == traget){
                    ans.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
                    //ans.push_back({nums[first] , nums[second] , nums[third]});
                }
            }
        }
        return ans;
    }
};