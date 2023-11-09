/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for(auto& c : s){
            if(isalnum(c)){
                str.push_back(tolower(c));
            }
        }
        int l = 0, r = str.size() - 1;
        while(l <= r){
            if(str[l] != str[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
};
// @lc code=end

