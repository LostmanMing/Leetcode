/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int l = i,r = i;l >= 0 && r < n;l--,r++){
                if(s[l] == s[r]) res++;
                else break;
            }
            for(int l = i, r = i + 1;l >= 0 && r < n;l--,r++){
                if(s[l] == s[r]) res++;
                else break;
            }
        }
        return res;
    }
};
// @lc code=end

