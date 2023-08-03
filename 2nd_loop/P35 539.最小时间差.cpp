// 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

// 示例 1：

// 输入：timePoints = ["23:59","00:00"]
// 输出：1
// 示例 2：

// 输入：timePoints = ["00:00","23:59","00:00"]
// 输出：0
 

// 提示：

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] 格式为 "HH:MM"

/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> t;
        for(auto& time : timePoints){
            auto h = stoi(time.substr(0,time.find(':')));
            auto m = stoi(time.substr(time.find(':') + 1));

            int num = h * 60 + m;
            t.push_back(num);
            t.push_back(num + 60 * 24);
        }
        sort(t.begin(),t.end());
        int res = INT_MAX;
        for(int i = 1;i < t.size();i++){
            res = min(res, t[i] - t[i-1]);
        }
        return res;
    }
};
// @lc code=end

