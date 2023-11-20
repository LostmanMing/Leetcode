/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        function<void()> dfs = [&]{
            if(path.size() == nums.size()){
                res.push_back(path);
                return ;
            }
            for(int i = 0;i < nums.size();i++){
                if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
                if(used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                dfs();
                path.pop_back();
                used[i] = false;
            }
        };

        dfs();
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

