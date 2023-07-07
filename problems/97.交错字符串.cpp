/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(),n2 = s2.size(),n3 = s3.size();
        if(n1 + n2 != n3) return false;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1,false)); //dp[i][j]数组表示以s1[i-1]之前的元素和s2[j-1]之前的元素能不能组成s3[i+j-2]之前的元素
        dp[0][0] = true;
        for(int i = 0;i <= n1;i++){
            for(int j = 0;j <= n2;j++){
                //下面两种情况都能满足条件
                if(i > 0 && dp[i-1][j] && s1[i-1]==s3[i+j-1]) dp[i][j]=true;
                if(j > 0 && dp[i][j-1] && s2[j-1]==s3[i+j-1]) dp[i][j]=true;
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

//题目
/**
 * 
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的
 * 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
 * 注意：a + b 意味着字符串 a 和 b 连接。
 * 示例 1：
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出：true
 * 
 * 
 * 
 * 
*/