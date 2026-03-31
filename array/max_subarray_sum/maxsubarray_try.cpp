class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int i = 0;
        while(i < nums.size() && nums[i] <= 0) ++i;
        int max = 0;
        while(i < nums.size() && nums[i] >= 0){
            max += nums[i];
            ++i;
        }
        while(i < nums.size()){
            int tmp = 0;
            while(i < nums.size() && nums[i] <= 0){ tmp += nums[i]; ++i; }
            while(i < nums.size() && nums[i] >= 0){ tmp += nums[i]; ++i; }
            if(tmp > 0) max += tmp;
        }
        return max;
    }
};