#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) ++need[c];

        int left = 0, right = 0;
        int valid = 0; // 已满足条件的字符种数
        int start = 0, minLen = INT_MAX;

        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) ++valid;
            }

            // 当所有字符都满足时，收缩左边
            while (valid == need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    --window[d];
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
