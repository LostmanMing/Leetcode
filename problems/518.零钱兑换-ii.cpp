/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0;i < n;i++){                     //先遍历物品，在遍历背包，物品顺序是固定的，不会出现乱排的情况，此时求得是组合数
            for(int j = coins[i];j <= amount;j++){
                dp[j] += dp[j - coins[i]];    //求数量都是累加
            }
        }
        return dp[amount];
    }
};
// @lc code=end

//题目
/**
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 * 
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 * 
 * 假设每一种面额的硬币有无限个。 
 * 
 * 题目数据保证结果符合 32 位带符号整数。
 * 
 * 示例 1：
 * 
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * 
*/