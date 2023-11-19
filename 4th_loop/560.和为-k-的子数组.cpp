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
        mp[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            int target = sum - k;
            if(mp.count(target)){
                res += mp[target];
            }
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end

