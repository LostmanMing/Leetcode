/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(),candidates.end());
        visited.resize(candidates.size(),false);
        dfs(candidates,0,0);
        return res;
    }

    void dfs(vector<int>& candidates, int start ,int sum){
        if(sum == target){
            res.push_back(path);
            return ;
        }
        if(sum > target) return ;

        for(int i = start;i < candidates.size();i++){
            if(i > 0 && candidates[i] == candidates[i-1] && visited[i-1]==false) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            visited[i] = true;
            dfs(candidates,i+1,sum);
            visited[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }

    int target;
    vector<bool> visited;
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

