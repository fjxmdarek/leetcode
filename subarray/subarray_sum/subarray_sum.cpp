class Solution {
    public:
    int subarraySum(vector<int> &nums , int k){
        unordered_map<int,int> curr_sum = {{0,1}};
        int sum = 0 , ans = 0;
        for(int &num : nums){
            sum += num;
            ans += curr_sum[sum-k];
            //if(sum == k) ++ans;
            ++curr_sum[sum];
        }
        return ans;
    }
};