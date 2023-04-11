// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem84.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;   // 定义单调递增栈
        heights.push_back(0);   //在 heights 尾部添加一个高度为 0 的元素，保证最后栈中的所有元素都可以弹出
        int n = heights.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){  // 如果栈顶元素大于等于当前元素，则弹出栈顶元素，计算以栈顶元素为高的最大面积
                int h = heights[st.top()];  // 栈顶元素的高度
                st.pop();
                if(st.empty())   // 如果栈为空，则说明栈顶元素为最小元素，计算面积时宽度为 i
                    res = max(res, i * h);
                else   // 否则计算面积时宽度为 (i - st.top() - 1)
                    res = max(res, (i - st.top() - 1) * h);
            }
            st.push(i);  // 将当前元素的下标入栈
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 示例 1:
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
*/
/*

// 注释：
// 1. 单调栈是一种数据结构，可以用来解决一些需要维护一段连续区间的最大值或最小值的问题。
// 2. 在该算法中，我们维护一个单调递增的栈，栈中存储元素下标。
// 3. 在遍历 heights 数组时，对于每个元素 heights[i]，如果它小于等于栈顶元素 heights[st.top()]，则将栈顶元素弹出，直到栈为空或者栈顶元素小于当前元素。
// 4. 在弹出每个栈顶元素时，计算以该元素为高的最大矩形面积，并更新最大值 res。
// 5. 由于最后要计算以 heights 尾部添加的高度为 0 的元素为高的最大面积，因此需要在 heights 尾部添加一个高度为 0 的元素。


*/