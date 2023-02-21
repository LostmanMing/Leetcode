/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int la = a.length() -1;
        int lb = b.length() -1;
        int rest = 0;
        while(la >= 0 || lb >= 0){
            int n1  = la >= 0 ? a[la] - '0': 0;
            int n2  = lb >= 0 ? b[lb] - '0': 0;
            int num = n1 + n2 + rest;
            ans.push_back('0' + num % 2);
            rest = num / 2;

            la--;
            lb--;
        }
        if(rest != 0) ans.push_back('0' + rest);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

