/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(),false);
        function<void(int,int)> dfs = [&](int start,int sum){
            if(sum == target){
                res.push_back(path);
                return ;
            }
            if(sum > target) return ;

            for(int i = start;i < candidates.size();i++){
                if(i > 0 && candidates[i] == candidates[i-1] && !used[i-1]) continue;
                used[i] = true;
                sum += candidates[i];
                path.push_back(candidates[i]);
                dfs(i+1,sum);
                path.pop_back();
                sum -= candidates[i];
                used[i] = false;
            }
        };

        dfs(0,0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

