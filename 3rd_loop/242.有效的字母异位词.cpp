/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> s_mp;
        unordered_map<char,int> t_mp;
        for(int i = 0;i < s.size();i++){
            s_mp[s[i]]++;
            t_mp[t[i]]++;
        }
        return s_mp == t_mp;
    }
};
// @lc code=end

