/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //i-1和j-1主要是为了避免复杂的初始化操作
        vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));  //dp表示 以i-1为结尾的num1和j-1为结尾的nums2中的最长公共子序列
        int res = 0;
        for(int i = 1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(dp[i][j], res);
                }
            }
        }
        return res;
    }
};
// @lc code=end
//题目
/**
 * 
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 * 
 * 示例 1：
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/
