class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size());
        ans[0] = 1;
        int right = nums[nums.size()-1];
        for(int i = 1 ; i < ans.size() ; i++) ans[i] = ans[i-1] * nums[i-1];
        for(int i = ans.size()-2 ; i >= 0 ; i--){
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};