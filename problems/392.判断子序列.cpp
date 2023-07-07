/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(),n2 = t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));  //dp[i][j]代表s[i-1]和t[j-1]的最长公共子序列
        for(int i = 1;i <= n1;i++){
            for(int j = 1;j <= n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[n1][n2]==n1;
    }
};
// @lc code=end

//题目

/**
 * 
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 示例 1：
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 * 
 * 
*/