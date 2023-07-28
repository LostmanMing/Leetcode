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

