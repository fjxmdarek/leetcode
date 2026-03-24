class Solution{
    public:
    int ConsecutiveNum(vector<int> &nums){
        unordered_set<int> num_set;
        for (const int& num : nums){
            num_set.insert(num);
        }

        int maxlen = 0;

        for (const int& num : nums){
            if(!num_set.count(num-1)){
                int currentnum = num;
                int currentlen = 1;

                while(num_set.count(currentnum+1)){
                    currentlen += 1;
                    currentnum +=1;
                }

                maxlen = max(maxlen,currentlen);
            }
        }
        return maxlen;
    }
};