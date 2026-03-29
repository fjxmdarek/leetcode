class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lookup;
        int ans = 0;
        int leftbound = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(lookup.find(s[i]) != lookup.end()){
                leftbound = max(leftbound,[s[i]] + 1);
            }
        ans = max(ans , i - leftbound + 1);
        lookup[s[i]] = i;
        }
    return ans;
    }
};