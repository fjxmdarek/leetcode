#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<char, int> travel(string x , int l , int r){
        unordered_map<char , int> x_table;
        for(int i = l ; i != r ; ++i){
            ++x_table[x[i]];
        }
        return x_table;
    }
    string minWindow(string s , string t) {
        unordered_map<char , int> t_table;
        t_table = travel(t , 0 , t.size());

        // 收集 s 中属于 t 的字符位置（按顺序）
        vector<pair<int,char>> pos;
        for(int i = 0 ; i < s.size() ; ++i)
            if(t_table.count(s[i])) pos.push_back({i , s[i]});

        unordered_map<char , int> window;
        int have = 0 , need = t_table.size();
        int left = 0 , ans_start = 0 , ans_len = INT_MAX;

        for(int right = 0 ; right < (int)pos.size() ; ++right){
            char c = pos[right].second;
            if(++window[c] == t_table[c]) ++have;

            // 满足条件时，收缩左端极点
            while(have == need){
                int len = pos[right].first - pos[left].first + 1;
                if(len < ans_len){ ans_len = len; ans_start = pos[left].first; }
                char lc = pos[left++].second;
                if(--window[lc] < t_table[lc]) --have;
            }
        }

        return ans_len == INT_MAX ? "" : s.substr(ans_start , ans_len);
    }
};
