// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

// 示例 1：

// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 示例 2：

// 输入：target = 4, nums = [1,4,4]
// 输出：1
// 示例 3：

// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
// 输出：0
 

// 提示：

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
 

// 进阶：

// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = 0;
        int num = 0;
        int res = n + 1;
        while(right < n){
            num += nums[right];
            while(num >= target){
                res = min(res,right - left + 1);
                num -= nums[left];
                left++;
            }
            right++;
        }
        return res == n+1 ? 0 : res;
    }
};
// @lc code=end

