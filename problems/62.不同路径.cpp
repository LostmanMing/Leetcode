/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));     //dp数组表示到i,j位置一共有多少条路径
        for(int i=0;i < m;i++){     //初始化左上边为1
            dp[i][0] = 1;
        }
        for(int j=0;j < n;j++){
            dp[0][j] = 1;
        }
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];     //递推公式
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

//题目
/**
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 * 示例 1：
 * 输入：m = 3, n = 7
 * 输出：28
 * 
 * 
 * 
 * 
 * 
*/