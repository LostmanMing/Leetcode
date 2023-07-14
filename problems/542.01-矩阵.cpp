/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include<vector>
#include<functional>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        // 创建一个与原矩阵大小相同的结果矩阵，初始化为-1
        vector<vector<int>> res(n,vector<int>(m,-1));
        // 定义四个方向的偏移量，用于遍历相邻位置
        vector<pair<int,int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        // 创建一个队列，用于BFS
        queue<pair<int,int>> q;
        // 将所有值为0的位置入队，并在结果矩阵中设置距离为0
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            int curx = cur.first;
            int cury = cur.second;
            // 遍历当前位置的四个相邻位置
            for(auto &d : dir){
                int nextx = curx + d.first;
                int nexty = cury + d.second;
                // 如果相邻位置在矩阵范围内且还未被访问过
                if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && res[nextx][nexty] == -1){
                    // 更新相邻位置的距离，并将其入队
                    res[nextx][nexty] = res[curx][cury] + 1;
                    q.push({nextx,nexty});
                }
            }
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 
 * 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
 * 
 * 
 * 两个相邻元素间的距离为 1 。
 * 
 * 示例 1：
 * 
 * 输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * 输出：[[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * 
 * 
*/