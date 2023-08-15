// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用 一次 。

// 注意：解集不能包含重复的组合。 

 

// 示例 1:

// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 输出:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// 示例 2:

// 输入: candidates = [2,5,2,1,2], target = 5,
// 输出:
// [
// [1,2,2],
// [5]
// ]
 

// 提示:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30



/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        function<void(int,int)> dfs = [&](int start,int sum){
            if(sum == target){
                res.push_back(path);
                return ;
            }
            if(sum > target) return;
            for(int i = start;i < candidates.size();i++){
                if(i > 0 && candidates[i] == candidates[i-1] && !used[i-1]){
                    continue;
                }
                path.push_back(candidates[i]);
                used[i] = true;
                sum += candidates[i];
                dfs(i + 1,sum);
                sum -= candidates[i];
                used[i] = false;
                path.pop_back();
            }
        };
        dfs(0,0);
        return res;
    }

    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

