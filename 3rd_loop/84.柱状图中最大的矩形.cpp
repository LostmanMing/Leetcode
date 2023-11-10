/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int res = 0;
        for(int i = 0;i < n;i++){
            int h = heights[i];
            while(!s.empty() && h < heights[s.top()]){
                int height = heights[s.top()];
                s.pop();
                if(s.empty()){
                    res = max(res,height * i);
                }else{
                    res = max(res, height * (i - s.top() - 1));
                }
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

