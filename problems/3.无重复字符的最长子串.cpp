/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include "string"
#include "unordered_map"
#include "algorithm"
#include "cmath"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> count;
        int l=0;
        int ret=0;
        for(int r=0;r<s.length();++r){
            count[s[r]]++;
            while(count[s[r]]>=2){
                count[s[l++]]--;
            }
            ret=max(ret,(r - l + 1));
        }
        return ret;
    }
};
// @lc code=end

