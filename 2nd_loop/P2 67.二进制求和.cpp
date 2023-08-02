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
        string res = "";
        int rest = 0;
        while(la >= 0 || lb >= 0){
            int n1 = la >= 0 ? a[la] - '0' : 0;
            int n2 = lb >= 0 ? b[lb] - '0' : 0;
            int num = n1 + n2 + rest;
            res.push_back(num % 2 + '0');
            rest = num / 2;
            la--; lb--;
        }
        if(rest != 0) res.push_back(rest + '0');
        reverse(res.begin(),res.end());
        return res;
    } 
};
// @lc code=end

// 二进制求和
// Category	Difficulty	Likes	Dislikes
// algorithms	Easy (53.34%)	963	-
// Tags
// Companies
// 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

 

// 示例 1：

// 输入:a = "11", b = "1"
// 输出："100"
// 示例 2：

// 输入：a = "1010", b = "1011"
// 输出："10101"
 

// 提示：

// 1 <= a.length, b.length <= 104
// a 和 b 仅由字符 '0' 或 '1' 组成
// 字符串如果不是 "0" ，就不含前导零