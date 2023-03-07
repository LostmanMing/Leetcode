/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, mul = 1;
        int left = 0, right = 0;
        while(right < n){
            // 将右端点向右移动并更新乘积
            mul *= nums[right];
            // 如果乘积大于等于k，左端点向右移动并更新乘积
            while(mul >= k && left <= right){
                mul /= nums[left];
                left++;
            }
            // 累加以右端点结尾且乘积小于k的子数组个数
            res += right - left + 1;
            // 将右端点向右移动
            right++;
        }
        return res;
    }
};
// @lc code=end

