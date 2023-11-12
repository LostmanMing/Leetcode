/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        dfs(candidates,0,0);
        return res;
    }

    void dfs(vector<int>& candidates, int start, int sum){
        if(sum == target){
            res.push_back(path);
            return ;
        }
        if(sum > target) return;
        for(int i = start;i < candidates.size();i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates,i,sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    int target;
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

