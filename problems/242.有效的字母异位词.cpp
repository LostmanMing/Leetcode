/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> table(26,0);
        for(auto &c : s){
            table[c - 'a']++;
        }
        for(auto &c : t){
            if(--table[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

