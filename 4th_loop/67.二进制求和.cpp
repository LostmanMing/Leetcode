/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size() - 1;
        int lb = b.size() - 1;
        int rest = 0;
        string res = "";
        while(la >= 0 || lb>= 0 || rest){
            int n1 = la >= 0 ? a[la] - '0' : 0;
            int n2 = lb >= 0 ? b[lb] - '0' : 0;

            int num = n1 + n2 + rest;
            res.push_back((num % 2) + '0');
            rest = num / 2;

            la--;
            lb--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

