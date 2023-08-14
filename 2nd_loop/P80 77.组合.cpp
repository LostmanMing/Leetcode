// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

 

// 示例 1：

// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// 示例 2：

// 输入：n = 1, k = 1
// 输出：[[1]]
 

// 提示：

// 1 <= n <= 20
// 1 <= k <= n




/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        function<void(int)> dfs = [&](int start) {
            if(path.size() == k){
                res.push_back(path);
                return ;
            }
            for(int i = start;i <= n;i++){
                path.push_back(i);
                dfs(i+1);
                path.pop_back();
            }
        };
        dfs(1);
        return res;
    }
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

