/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<bool> used;
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

