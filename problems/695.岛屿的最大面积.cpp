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
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0)); 
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && grid[i][j] == 1){  //跳过遍历过的以及海水区域
                    count = 0;
                    dfs(grid,visited,i,j);
                    res = max(res,count);
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int x,int y){
        if(!grid[x][y] || visited[x][y])  return ;  //终止条件：访问过或者遇到海水
        count++;
        visited[x][y] = true;
        for(int i = 0;i < 4;i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx >= grid.size() || nextx < 0 || nexty >= grid[0].size() || nexty < 0 ) continue;  //越界
            dfs(grid, visited, nextx, nexty);
        }
    }
    int count = 0;
    int dir[4][2]{0,1,1,0,0,-1,-1,0}; //上 右 下 左 
};
// @lc code=end

//题目

/**
 * 
 * 给你一个大小为 m x n 的二进制矩阵 grid 。
 * 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
 * 岛屿的面积是岛上值为 1 的单元格的数目。
 * 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 * 
 * 示例 1：
 * 输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 输出：6
 * 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
 * 
 * 
 * 
 * 
*/