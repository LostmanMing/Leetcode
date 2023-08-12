// 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

// 请你找出并返回只出现一次的那个数。

// 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

 

// 示例 1:

// 输入: nums = [1,1,2,3,3,4,4,8,8]
// 输出: 2
// 示例 2:

// 输入: nums =  [3,3,7,7,10,11,11]
// 输出: 10
 

// 提示:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

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

