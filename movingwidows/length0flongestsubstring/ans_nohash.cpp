int lengthOfLongestSubstring(char* s) {
    int ans = 0;
    char* l = s;
    while (*s != '\0') {
        char* idx = strchr(l, *s);
        if (idx != s) {
            l = idx + 1;
        }
        ans = max(ans, s - l + 1);
        s++;
    }
    return ans;
}