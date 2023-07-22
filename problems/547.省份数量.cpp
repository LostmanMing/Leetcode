// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
#include<vector>
#include<queue>
#include<functional>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        queue<int> q;
        function<void(int)> bfs = [&](int city){
            q.push(city);
            visited[city] = 1;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(int i = 0;i < n;i++){
                    if(isConnected[front][i] == 1 && !visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        };
        int res = 0;
        for(int i = 0;i < n;i++){
            if(visited[i] == 0){
                bfs(i);
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
 * 
 * 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 * 
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
 * 
 * 返回矩阵中 省份 的数量。
 * 
 * 
 * 
*/