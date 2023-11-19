/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, res = n+1;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                res = min(r - l + 1, res);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return res == n+1 ? 0 : res;
    }
};
// @lc code=end

