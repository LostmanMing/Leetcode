// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = 0;
        int num = 0;
        int res = n + 1;
        while(right < n){
            num += nums[right];
            while(num >= target){
                res = min(res,right - left + 1);
                num -= nums[left];
                left++;
            }
            right++;
        }
        return res == n+1 ? 0 : res;
    }
};
// @lc code=end

