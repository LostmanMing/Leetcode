/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umapi;
        for(int i =0;i<nums.size();++i){
            int res = target - nums[i];
            if(umapi.find(res) != umapi.end()) { 
                return {umapi[res],i};
            }
                umapi[nums[i]] = i;
        }
        return {-1,-1};    
    }
};
// @lc code=end

