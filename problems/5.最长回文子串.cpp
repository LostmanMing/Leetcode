/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include "string"
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i < s.length();i++){

            int l = i - 1;
            int r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]) {l--; r++;};
            if(ans.length() < r - l -1)  ans = s.substr(l + 1, r - l -1);
            l = i; r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]) {l--; r++;};
            if(ans.length() < r - l -1)  ans = s.substr(l + 1, r - l -1);
        }
        return ans;
    }
};
// @lc code=end

