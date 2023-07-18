/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        function<void(int)> dfs = [&](int x){
            if(x == graph.size() -1){
                res.push_back(path);
                return ;
            }
            for(int i = 0;i < graph[x].size();i++){
                path.push_back(graph[x][i]);
                dfs(graph[x][i]);
                path.pop_back();    //回溯
            }
        };
        path.push_back(0);
        dfs(0);
        return res;
    }
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

//题目
/**
 * 
 * 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
 * 
 *  graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
 * 
 * 示例 1：
 * 
 * 输入：graph = [[1,2],[3],[3],[]]
 * 输出：[[0,1,3],[0,2,3]]
 * 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/