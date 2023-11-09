/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;r--;
            }else{
                return check(s,l,r-1) || check(s,l+1,r);
            }
        }
        return true;
    }
    bool check(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end

