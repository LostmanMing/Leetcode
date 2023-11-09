/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        int res = 0;
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

