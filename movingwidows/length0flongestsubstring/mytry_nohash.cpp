int lengthOfLongestSubstring(string str) {
    char* s = &str[0];
    int ans = 0;
    char* l = s;
    while(*s != '\0'){
        char* index = strchr(l , *s);
        if(index != s){
            l = index + 1;
        }
        ans = max(ans , (int)(s-l+1));
        s++;
    }
    return ans;
}