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
        vector<vector<int>> ans;
        //排序
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        ans.push_back(intervals[0]);
        //遍历
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0] <= ans.back()[1]){  //如果当前元素开始比结果中保存的最后一个的结束还小，说明有重叠
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);  //更新重叠区间结束为更大的那个
            }else{
                ans.push_back(intervals[i]);  //没有重叠直接进结果。
            }
        }
        return ans;
    }
};
// @lc code=end

