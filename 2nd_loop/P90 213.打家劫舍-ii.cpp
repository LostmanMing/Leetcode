// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 

// 示例 1：

// 输入：nums = [2,3,2]
// 输出：3
// 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 示例 2：

// 输入：nums = [1,2,3,1]
// 输出：4
// 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 示例 3：

// 输入：nums = [1,2,3]
// 输出：3
 

// 提示：

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000



/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> sub1(nums.begin(),nums.end() - 1);
        vector<int> sub2(nums.begin() + 1,nums.end());
        return max(cal(sub1),cal(sub2));
    }
    int cal(vector<int>& sub){
        int n  = sub.size();
        if(n == 1) return sub[0];
        vector<int> dp(n,0);
        dp[0] = sub[0];
        dp[1] = max(sub[0],sub[1]);
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i-1],dp[i-2] + sub[i]);
        }
        return dp[n-1];
    }
};
// @lc code=end

