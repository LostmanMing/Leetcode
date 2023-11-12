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
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());

        return max(func(nums1),func(nums2));
    }

    int func(vector<int>& nums){
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int> dp(n,0);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
// @lc code=end

