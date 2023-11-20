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
        int l = 0, r = n-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(arr[m] > arr[m-1] && arr[m] > arr[m+1]){
                return m;
            }else if (arr[m] > arr[m-1] && arr[m] < arr[m+1]){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }
};
// @lc code=end

