// 给你一个大小为 m x n 的二进制矩阵 grid 。

// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

// 岛屿的面积是岛上值为 1 的单元格的数目。

// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

 

// 示例 1：


// 输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 输出：6
// 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
// 示例 2：

// 输入：grid = [[0,0,0,0,0,0,0,0]]
// 输出：0
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] 为 0 或 1


/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    cnt = 0;
                    dfs(grid,visited,i,j);
                    res = max(res,cnt);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
        if(grid[x][y] != 1 || visited[x][y]){
            return ;
        }
        cnt++;
        visited[x][y] = true;
        for(int i = 0;i < 4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
            dfs(grid,visited,nx,ny);
        }
    }
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    int cnt = 0;
};
// @lc code=end

