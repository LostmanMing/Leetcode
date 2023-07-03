/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(2,0)); //第i个字符翻转为0时满足单调递增的最小翻转次数
        int n = s.size();
        if(n == 1) return 0;
        if(s[0]== '0'){
            dp[0][0] = 0;
            dp[0][1] = 1;
        }else{
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        for(int i = 1;i < s.size();i++){
            if(s[i] == '0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 1;
            }
            if(s[i] == '1'){
                dp[i][0] = dp[i-1][0] + 1 ;
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]);
            }

        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};
// @lc code=end

//题目
/**
 * 如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。
 * 
 * 给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。
 * 
 * 返回使 s 单调递增的最小翻转次数。
 * 
 * 示例 1：
 * 输入：s = "00110"
 * 输出：1
 * 解释：翻转最后一位得到 00111
 * 
 * 
 * 
*/