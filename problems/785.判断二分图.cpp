/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);  //记录每个节点的颜色  0：未染色 1:染色1 -1:颜色2
        //将相邻节点都染成自己相反的颜色，如果没有冲突说明可以二分图，否则不行
        function<bool(int,int)> dfs = [&](int cur,int color) -> bool {
            if(colors[cur] != 0){
                return colors[cur] == color;   //结束条件:如果已经被染色并且和需要被染的颜色冲突，返回false，否则返回true
            }
            colors[cur] = color;    //给当前节点染color颜色
            for(auto &node : graph[cur]){
                if(!dfs(node,-color)) return false; //给相邻节点染相反颜色
            }
            return true;
        };
        for(int i = 0;i < n;i++){
            if(colors[i] == 0 && !dfs(i,1)){   //遍历每个未涂色节点
                return false;
            }
        }
        return true;
    } 
};
// @lc code=end

//题目
/**
 * 
 * 存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：
 * 
 * 不存在自环（graph[u] 不包含 u）。
 * 不存在平行边（graph[u] 不包含重复值）。
 * 如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
 * 这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
 * 二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 
 * 如果图是二分图，返回 true ；否则，返回 false 。
 * 示例 1：
 * 输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * 
 * 输出：false
 * 解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。 
 * 
 * 
*/