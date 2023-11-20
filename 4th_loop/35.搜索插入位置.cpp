/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] >target){
                r = m - 1;
            }else if(nums[m] < target){
                l = m + 1;
            }else{
                return m;
            }
        }
        return l;
    }
};
// @lc code=end

