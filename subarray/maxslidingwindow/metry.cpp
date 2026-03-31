class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int>& nums , int k) {
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);  // 加这行
        deque<int> dq;
        int i=-1,j=-k;
        while(j<(int)nums.size()-k){
            ++i;
            if(j>=0 && dq.front()==nums[j]) dq.pop_front();
            while(!dq.empty() && nums[i] > dq.back() ) dq.pop_back();
            dq.push_back(nums[i]);
            ++j;
            if(j>=0) ans.push_back(dq.front());
        }
    return ans;    
    }
};