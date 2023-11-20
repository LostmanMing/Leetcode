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
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        for(int i = 0;i < s.size();i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        return mps == mpt;
    }
};
// @lc code=end

