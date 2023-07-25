// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(auto &e : edges){
            if(!same(e[0],e[1])){
                join(e[0],e[1]);
            }else{
                return e;
            }
        }
        return vector<int>{};
    }
private:
    void init(){
        for(int i = 0;i < n;i++){
            father[i] = i;
        }
    }
    void join(int u ,int v){
        u = father[u];
        v = father[v];
        if(u == v) return ;
        father[v] = u;
    }
    bool same(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }
    int find(int u){
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    int n = 1005;
    int father[1005];
};
// @lc code=end

//题目

/**
 * 
 * 树可以看成是一个连通且 无环 的 无向 图。
 * 
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
 * 
 * 示例 1：
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 * 
 * 
 * 
 * 
*/