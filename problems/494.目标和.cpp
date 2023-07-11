/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int bagsize = (target + sum) / 2;     //只要nums中的元素能组成bagsize这么大的正数，就能满足结果
        if(abs(target) > sum) return 0;
        if((target + sum) % 2 != 0) return 0;
        vector<int> dp(bagsize+1,0);    //dp[j] 表示：填满j（包括j）这么大容积的包，有dp[j]种方法
        dp[0] = 1;
        for(int i = 0;i < nums.size();i++){
            for(int j = bagsize;j >= nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[bagsize];
    }
};
// @lc code=end


//题目
/**
 * 
 * 给你一个整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 示例 1：
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 
 * 
*/
