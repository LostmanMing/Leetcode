/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {      //本题不需要回文串连续
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));   //i.j范围内最长回文串
        for(int i = 0;i < n;i++){
            dp[i][i] = 1;                             //二层循环中点
        }
        for(int i = n - 1;i >= 0;i--){
            for(int j = i + 1;j < n;j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;     //两边相等直接加2
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);    //否则考虑单边哪个最大
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

//题目
/**
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 
 * 
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 * 
 * 
 * 示例 1：
 * 输入：s = "bbbab"
 * 输出：4
 * 
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 * 
 * 
 * 
 * 
 * 
*/