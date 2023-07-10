// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum/2;
        vector<int>dp(target+1,0);
        if(sum % 2 != 0) return false;
        for(int i = 0;i < nums.size();i++){
            for(int j = target;j >= nums[i];j--){
                dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[target] == target) return true;
        else return false;
    }
};
// @lc code=end

//题目
/**
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 
*/