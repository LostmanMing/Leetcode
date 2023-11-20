/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        function<void(int,int)> dfs = [&](int start,int sum){
            if(sum == target){
                res.push_back(path);
                return ;
            }
            if(sum > target) return ;
            for(int i = start;i < candidates.size();i++){
                sum += candidates[i];
                path.push_back(candidates[i]);
                dfs(i,sum);
                path.pop_back();
                sum -= candidates[i];
            }
        };

        dfs(0,0);
        return res;
    }
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

