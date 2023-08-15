/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        function<void(int)> dfs = [&](int start){
            if(path.size() == nums.size()){
                res.push_back(path);
                return ;
            }

            for(int i = 0;i < nums.size();i++){
                if(used[i]) continue;
                path.push_back(nums[i]);
                used[i] = true;
                dfs(i);
                path.pop_back();
                used[i] = false;
            }
        };
        dfs(0);
        return res;
    }
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

