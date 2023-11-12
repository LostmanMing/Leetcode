/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used.resize(nums.size(),false);
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return ;
        }

        for(int i = 0;i < nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<bool> used;
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

