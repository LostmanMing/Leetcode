// 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

// 示例 1：


// 输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// 输出：6
// 解释：最大矩形如上图所示。
// 示例 2：

// 输入：matrix = []
// 输出：0
// 示例 3：

// 输入：matrix = [["0"]]
// 输出：0
// 示例 4：

// 输入：matrix = [["1"]]
// 输出：1
// 示例 5：

// 输入：matrix = [["0","0"]]
// 输出：0
 

// 提示：

// rows == matrix.length
// cols == matrix[0].length
// 1 <= row, cols <= 200
// matrix[i][j] 为 '0' 或 '1'
/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& height){
        int n = height.size();
        stack<int> st;
        int res = 0;
        height.push_back(0);
        for(int i = 0;i < n + 1;i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int h = height[st.top()];
                st.pop();
                if(st.empty()) res = max(res, i * h);
                else res = max(res, (i - st.top() - 1) * h);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

