/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(s - sum == sum - nums[i]) return i;
        }
        return -1;
    }
};
// @lc code=end

