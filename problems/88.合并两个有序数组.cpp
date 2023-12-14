/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m + n - 1;m > 0 && n > 0 && i >= 0;i--){
            if(nums1[m-1] > nums2[n-1]){
                nums1[i] = nums1[m-1];
                m--;
            }else{
                nums1[i] = nums2[n-1];
                n--;
            }
        }

        for(int i = 0;i < n;i++){
            nums1[i] = nums2[i];
        }
    }
};
// @lc code=end

