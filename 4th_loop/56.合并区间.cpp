/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(auto& i : intervals){
            if(i[0] > res.back()[1]){
                res.push_back(i);
            }else{
                res.back()[1] = max(i[1],res.back()[1]);
            }
        }
        return res;
    }
};
// @lc code=end

