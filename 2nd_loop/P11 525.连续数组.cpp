// 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

 

// 示例 1:

// 输入: nums = [0,1]
// 输出: 2
// 说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
// 示例 2:

// 输入: nums = [0,1,0]
// 输出: 2
// 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 

// 提示：

// 1 <= nums.length <= 105
// nums[i] 不是 0 就是 1

/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int res = 0, sum = 0;
        for(int i = 0;i < n;i++){
            sum += (nums[i] == 0 ? -1 : 1);
            if(mp.count(sum)){
                res = max(res, i - mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return res;
    }
};
// @lc code=end

