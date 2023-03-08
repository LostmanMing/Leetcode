/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {               //前缀和  + 哈希表
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = 1;
        int n = nums.size();
        int sum = 0,res = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];    //计算当前位置前缀和
            if(mp.count(sum - k)){
                res += mp[sum - k];
            }
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end

