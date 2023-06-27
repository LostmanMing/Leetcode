/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        if(n==1) return 1;
        if(n==2) return 2;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end

//题目
/**
 * 
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 示例 1：
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
*/