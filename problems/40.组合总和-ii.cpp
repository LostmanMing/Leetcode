// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

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
    void dfs(int startIdx, int target, const vector<int>& candidates, int sum,vector<bool>& used){
        if(sum == target){
            res.push_back(path);
            return ;
        }
        if(sum > target) return ;

        for(int i = startIdx;i < candidates.size() && sum + candidates[i] <= target;i++){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false){
                continue;
            } 
            path.push_back(candidates[i]);
            used[i] = true;
            sum += candidates[i];
            dfs(i+1,target,candidates,sum,used);
            path.pop_back();
            used[i] = false;
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        dfs(0,target,candidates,0,used);
        return res;
    } 
private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

