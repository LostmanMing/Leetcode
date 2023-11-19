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
        int l = 0, r= 0;
        int cul = 1;
        int res = 0;
        while(r < n){
            cul *= nums[r];
            while(l <= r && cul >= k){
                cul /= nums[l];
                l++;
            }
            res += (r - l) + 1;
            r++;
        }
        return res;
    }
};
// @lc code=end

