/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& n : nums){
            mp[n]++;
        }
        for(auto& m:mp){
            if(m.second == 1) return m.first;
        }
        return {};
    }
};
// @lc code=end

