/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));// 创建一个与矩阵大小相同的二维数组 dp，用于存储每个单元格的最长递增路径长度
        vector<pair<int,int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        function<int(int,int)> dfs = [&](int x,int y) -> int{
            if(dp[x][y] != 0) return dp[x][y]; // 如果当前单元格已经计算过最长路径，则直接返回其值
            int maxlen = 1;
            for(int i = 0;i < 4;i++){
                int newx = x + dir[i].first;
                int newy = y + dir[i].second;
                // 判断新坐标是否越界，以及是否递增
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && matrix[newx][newy] > matrix[x][y]){
                    maxlen = max(maxlen, 1 + dfs(newx,newy));  //更新最长路径
                }
            }
            dp[x][y] = maxlen;
            return maxlen;
        };
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res = max(res, dfs(i,j));
            }
        }
        return res;
    }
};
// @lc code=end

//题目

/**
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 示例 1：
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 
 * 
 * 
*/