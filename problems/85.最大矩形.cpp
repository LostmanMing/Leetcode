// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem85.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> height(matrix[0].size() + 1, 0);
        int res = 0;
        for(int i = 0;i < matrix.size();i++){                  //每一加一行计算一次柱图中最大矩形
            for(int j = 0;j < matrix[0].size();j++){   
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1; //第二行中数据是 0 ，那么不管第一行是什么，高度都是 0
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        int res = 0;
        for(int i = 0;i < heights.size();i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int h = heights[st.top()];
                st.pop();
                if(st.empty())
                    res = max(res, h * i);
                else
                    res = max(res, (i - st.top() -1) * h);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例 1：
 * 输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
*/
/*

思路
如果只有一行，把每个格子中的数据看成是高度，那么就是 [84. 柱状图中最大的矩形]
如果只有两行，我想得到第二行中所有数据的高度
第二行中数据是 1 ，如果上面第一行也是 1 ，高度就是 2 ，否则是 1
第二行中数据是 0 ，那么不管第一行是什么，高度都是 0
因此，遍历每一行时，都能够得到以这一行为底的带高度的数组
将其代入 【柱状图中最大的矩形】单调栈入门，使用单调栈快速寻找边界 的代码中进行计算
记录最大值得到答案

*/