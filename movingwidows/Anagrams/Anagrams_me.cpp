#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    vector<int> findAnagrams(string s , string p) {
        vector<int> ans;
        int length = p.size();
        unordered_map<char,int> p_table;
        int i = 0 , j = length-1;
        while(i <= j){
            ++p_table[p[i]];
            ++i;
        }

        unordered_map<char,int> s_table;
        for(int k = 0; k < length; k++)
            ++s_table[s[k]];

        i = 0 , j = length-1;
        while(j < (int)s.size()){
            if(s_table == p_table) ans.push_back(i);
            j++;
            if(j < (int)s.size()) ++s_table[s[j]];
            if(--s_table[s[i]] == 0) s_table.erase(s[i]);
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd", p = "abc";
    vector<int> result = sol.findAnagrams(s, p);
    cout << "s=\"" << s << "\", p=\"" << p << "\" -> [";
    for (int i = 0; i < result.size(); i++) {
        if (i) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
    return 0;
}