/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1; 
        while(l  < r){     
            int mid = l + (r - l) / 2;
            if(arr[mid] < arr[mid + 1])  l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
// @lc code=end

