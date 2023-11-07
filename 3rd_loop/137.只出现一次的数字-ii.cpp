/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(auto &n : nums){
            mp[n]++;
        }
        for(auto &m : mp){
            if(m.second == 1) return m.first;
        }
        return -1;
    }
};
// @lc code=end

