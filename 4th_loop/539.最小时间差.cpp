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
        vector<int> times;
        for(auto& time : timePoints){
            int h = stoi(time.substr(0,time.find(':')));
            int m = stoi(time.substr(time.find(':')+1));

            int t = h * 60 + m;
            times.push_back(t);
            times.push_back(t + 60*24);
        }
        sort(times.begin(),times.end());
        int res = INT_MAX;
        for(int i = 1;i < times.size();i++){
            res = min(times[i] - times[i-1],res);
        }
        return res;
    }
};
// @lc code=end

