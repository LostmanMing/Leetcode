// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1,INT_MAX); //凑足总额为j所需钱币的最少个数为dp[j]
        dp[0] = 0;
        for(int i = 0;i < n;i++){
            for(int j = coins[i];j <= amount;j++){
                if(dp[j-coins[i]] != INT_MAX){
                    //凑足总额为j - coins[i]的最少个数为dp[j - coins[i]]，那么只需要加上一个钱币coins[i]即dp[j - coins[i]] + 1就是dp[j]（考虑coins[i]）
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        else return dp[amount];
    }
};
// @lc code=end

//题目
/**
 * 
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 示例 1：
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1s
 * 
 * 
 * 
*/