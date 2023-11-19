/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r){
            if(s[l] != s[r]){
                return is_hw(s,l,r-1) || is_hw(s,l+1,r);
            }
            l++;
            r--;
        }
        return true;
    }

    bool is_hw(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end

