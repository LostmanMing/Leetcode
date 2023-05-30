/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n -1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(m % 2 == 0){ // 判断 m 是否为偶数
                if(nums[m]==nums[m+1]){ // m 与 m+1 相等，说明目标元素在右侧
                    l = m + 1;
                }else{  // m 与 m+1 不相等，且 m 不是第一个元素，说明目标元素在左侧
                    if(m == 0 || nums[m] != nums[m-1]) return nums[m];
                    r = m - 1;
                }
            }else{
                if(nums[m] == nums[m-1]){ // m 与 m-1 相等，说明目标元素在右侧
                    l = m + 1;
                }else{ // m 与 m-1 不相等，且 m 不是最后一个元素，说明目标元素在左侧
                    if(nums[m] != nums[m+1]) return nums[m];
                    r = m - 1;
                }
            }
        }
        return nums[r];  
    }
};
// @lc code=end

//题目
/**
 * 
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 * 请你找出并返回只出现一次的那个数。
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 * 
 * 
 * 示例 1:
 * 输入: nums = [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */