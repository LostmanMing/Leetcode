/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int l = 1, r = n - 2;
        while(l < r){
            int m = l + (r - l) / 2;
            if(m % 2 == 1){
                if(nums[m] == nums[m-1]){
                    l = m + 1;
                }else{
                    if(nums[m] != nums[m+1]) return nums[m];
                    r = m - 1;
                }
            }else{
                if(nums[m] == nums[m+1]){
                    l = m + 1;
                }else{
                    if(nums[m] != nums[m-1]) return nums[m];
                    r = m - 1;
                }
            }
        }
        return nums[l];
    }
};
// @lc code=end

