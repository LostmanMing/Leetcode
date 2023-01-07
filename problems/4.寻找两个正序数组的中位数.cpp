/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#include "vector"
#include "functional"
#include "algorithm"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = (nums1.size() + nums2.size());
        if( n % 2 == 0){                                 //总数为偶数的情况
            int left = find(nums1,0,nums2,0,n/2);   
            int right = find(nums1,0,nums2,0,n / 2 + 1);
            return (left + right) / 2.0;
        }else{
            return find(nums1,0,nums2,0,n/2 + 1);
        }
    }
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size() - i > nums2.size() - j){        //只能判断第一数组个数小于第二个数组个数，如果大于，需要反转
            return find(nums2,j,nums1,i,k);
        } 
        if(nums1.size() == i) return nums2[j + k -1];  //第一个数组为空

        if(k == 1) return min(nums1[i],nums2[j]);      //二分查找结束，递归出口

        int idx1 = min((int)nums1.size(), i + k / 2);  //不能越界

        int idx2 = j + k - k / 2;   
        if(nums1[idx1 - 1] < nums2[idx2 - 1]){         //如果上边小于下边，删除上边小的元素，并将k减去删除元素个数（这些元素为小于数组2同位置的元素）
            return find(nums1, idx1, nums2,j ,k - (idx1 - i));
        }else{
            return find(nums1, i, nums2, idx2, k - (idx2 - j));
        }
    }
};
// @lc code=end

