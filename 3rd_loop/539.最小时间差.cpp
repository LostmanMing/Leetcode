/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        vector<int> tp;
        for(int i = 0;i < n;i++){
            string t = timePoints[i];
            auto h = t.substr(0,t.find(':'));
            auto m = t.substr(t.find(':') + 1);

            auto time = 60 * stoi(h) + stoi(m);
            tp.push_back(time);
            tp.push_back(time + 60 * 24);
        }
        sort(tp.begin(),tp.end());
        int res = INT_MAX;
        for(int i = 1;i < tp.size();i++){
            res = min(res,tp[i] - tp[i-1]);
        }
        return res;
    }
};
// @lc code=end

