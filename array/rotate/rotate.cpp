class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        vector<int> tail;
        tail.resize(k);
        for(int i = nums.size() - k - 1, j = 0; j < k; i++, j++){
            tail[j] = nums[i];
        } 
        for(int i = nums.size() - k - 1; i >= 0 ; i--){
            nums[i + k] = nums[i];
        }
        for(int i = 0 ; i < k ; i++){
            nums[i] = tail[i];
        }
    }
};