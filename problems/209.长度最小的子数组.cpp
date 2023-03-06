/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// 滑动窗口，双指针实现

#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sizes = nums.size();
        int left = 0, right = 0;
        int res = sizes + 1;
        int sum = 0;
        while(right < sizes){
            sum += nums[right];
            while(sum >= target){
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == sizes + 1 ? 0 : res;
    }
};
// @lc code=end

