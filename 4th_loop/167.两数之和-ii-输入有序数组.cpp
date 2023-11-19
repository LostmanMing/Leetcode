/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++){
            int num = target - numbers[i];
            if(mp.count(num)) return {mp[num]+1,i+1};
            mp[numbers[i]] = i;
        }
        return {-1,-1};
    }
};
// @lc code=end

