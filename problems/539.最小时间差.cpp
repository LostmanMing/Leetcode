/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    //为了考虑跨越午夜的情况将每个时间点加上24小时，确保我们计算的时间差始终是从较小的时间点到较大的时间点之间的时间差
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();      
        vector<int> nums(2*n);                //保存当天以及下一天当前时间的时间长度
        for(int i = 0, idx = 0;i < n; i++, idx += 2){
            string time = timePoints[i];
            int h = stoi(time.substr(0,time.find(":")));      //拿到小时
            int m = stoi( time.substr(time.find(":") + 1));   //拿到分钟
            
            nums[idx] = h * 60 + m;      //当天的时间
            nums[idx + 1] = nums[idx] + 1440;  //第二天的时间
        }
        sort(nums.begin(), nums.end());
        int ans = nums[1] - nums[0];    //计算时间差
        for(int i = 2; i < 2 * n; i++){
            ans = min(ans, (nums[i] - nums[i-1])); //计算最小时间差
        }
        return ans;
    }
};
// @lc code=end

//题目
/**
 * 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
 * 
 * 示例 1：
 * 输入：timePoints = ["23:59","00:00"]
 * 输出：1
 * 
 * 示例 2：
 * 输入：timePoints = ["00:00","23:59","00:00"]
 * 输出：0
 * 
*/
/*
将时间点加上24小时（1440分钟）是为了考虑跨越午夜的情况。
例如，如果给定的时间点是23:00和01:00，则它们之间的时间差为2小时，但如果给定的时间点是01:00和23:00，则它们之间的时间差应该是22小时。
因此，我们将每个时间点加上24小时，这样可以确保我们计算的时间差始终是从较小的时间点到较大的时间点之间的时间差。
在这种情况下，即使时间跨越了午夜，我们仍然可以正确地计算时间差。
*/