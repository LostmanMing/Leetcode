/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> res(n,0);
        for(int i = 0;i < n;i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

