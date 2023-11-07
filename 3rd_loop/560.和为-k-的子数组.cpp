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
#include <vector>
using namespace std;
#include <unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int res = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            int num = sum-k;
            if(mp.count(num)){
                res += mp[num];
            }
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end

