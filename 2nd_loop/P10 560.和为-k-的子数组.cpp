// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。

 

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2
 

// 提示：

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem560.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1; // sum正好等于k是sum-k=0此时需要一个初始值。
        int sum = 0,res=0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(mp.count(sum - k)){
                res += mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end

