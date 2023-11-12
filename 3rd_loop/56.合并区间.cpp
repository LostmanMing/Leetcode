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
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

