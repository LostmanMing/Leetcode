// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> path; // 用来存放符合条件结果
    vector<vector<int>> res;// 存放符合条件结果的集合
    void dfs(int startIdx, int n, int k){
        if(path.size() == k){        //递归终止条件
            res.push_back(path);
            return ;
        }
        for(int i = startIdx;i <= n;i++){// 控制树的横向遍历
            path.push_back(i); // 处理节点 
            dfs(i + 1,n,k); // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return res;
    }
};
// @lc code=end

//题目
/**
 * 
 * 
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 示例 1：
 * 输入：n = 4, k = 2
 * 输出：
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/
