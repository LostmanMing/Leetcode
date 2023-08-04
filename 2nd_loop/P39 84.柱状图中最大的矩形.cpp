// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

// 示例 1:



// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10
// 示例 2：



// 输入： heights = [2,4]
// 输出： 4
 

// 提示：

// 1 <= heights.length <=105
// 0 <= heights[i] <= 104

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
        int n = heights.size();
        stack<int> st;
        heights.push_back(0);
        int res = 0;
        for(int i = 0;i < n+1;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                if(st.empty()){
                    res = max(res, h * i);
                }else{
                    res = max(res, h * (i - st.top() - 1));
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

