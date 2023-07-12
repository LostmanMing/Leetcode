// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem377.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1,0);
        dp[0] = 1;
        for(int j = 0;j <= target;j++){      //先遍历背包，在遍历物品，这样才可以让后面的物品出现在前面，此时求得是排列数
            for(int i = 0;i < n;i++){
                //C++测试用例有两个数相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]
                if(j >= nums[i] && dp[j] <= INT_MAX - dp[j-nums[i]]){
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

//题目
/**
 * 
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 
 * 题目数据保证答案符合 32 位整数范围。
 * 
 * 示例 1：
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
*/
