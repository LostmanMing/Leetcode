// 符合下列属性的数组 arr 称为 山脉数组 ：
// arr.length >= 3
// 存在 i（0 < i < arr.length - 1）使得：
// arr[0] < arr[1] < ... arr[i-1] < arr[i] 
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
// 给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

// 你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

 

// 示例 1：

// 输入：arr = [0,1,0]
// 输出：1
// 示例 2：

// 输入：arr = [0,2,1,0]
// 输出：1
// 示例 3：

// 输入：arr = [0,10,5,2]
// 输出：1
 

// 提示：

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// 题目数据保证 arr 是一个山脉数组

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
        int l = 0, r = n -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m]  >  arr[m - 1] && arr[m] > arr[m + 1]) return m;
            else if(arr[m] > arr[m-1] && arr[m] < arr[m + 1]){
                l = m + 1;
            }
            else r = m;
        }
        return l;
    }
};
// @lc code=end

