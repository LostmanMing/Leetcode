/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);     //存储对应课程的入度，即还需要几门课程才能学我
        vector<vector<int>> lst(numCourses,vector<int>());   //存储学完当前课程可以让哪些课程入度减1；
        for(auto v : prerequisites){   //初始化入度和节点间的关系
            inDegree[v[0]]++;
            lst[v[1]].push_back(v[0]);
        }
        vector<int> res;
        //BFS
        queue<int> q;                             
        for(int i = 0;i < inDegree.size();i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            res.push_back(front);
            for(auto & v : lst[front]){
                if(--inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
        
    }
};
// @lc code=end

//题目
/**
 * 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
 * 
 * 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
 * 
 * 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
 * 
 * 示例 1：
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：[0,1]
 * 解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 * 
 * 
 * 
 * 
*/