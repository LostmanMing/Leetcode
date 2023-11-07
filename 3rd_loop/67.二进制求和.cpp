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
        int la = a.size() - 1;
        int lb = b.size() - 1;
        string res = "";
        int rest = 0;
        while(la >= 0 || lb >= 0){
            int na = la >= 0 ? a[la] - '0' : 0;
            int nb = lb >= 0 ? b[lb] - '0' : 0;
            int num = rest + na + nb;
            res.push_back((num % 2) + '0');
            rest = num / 2;
            la--;
            lb--;
        }
        if(rest != 0) res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

