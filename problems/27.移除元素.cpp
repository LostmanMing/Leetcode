/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size();
        while(l < r){
            if(nums[l] == val){
                nums[l] = nums[r-1];
                r--;
            }else{
                l++;
            }
        }
        return l;
    }
};
// @lc code=end

