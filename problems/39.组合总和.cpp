// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void dfs(int startIdx, vector<int> candidates,int target,int sum){
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(sum > target) return;
        for(int i = startIdx;i<candidates.size() ;i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(i, candidates, target,sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,candidates,target,0);
        return res;
    }
};
// @lc code=end

