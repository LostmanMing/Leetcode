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
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        function<void()> dfs = [&](){
            if(path.size() == nums.size()){
                res.push_back(path);
                return ;
            }
            for(int i = 0;i < nums.size();i++){
                if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])){
                    continue;
                }
                path.push_back(nums[i]);
                used[i] = true;
                dfs();
                path.pop_back();
                used[i] = false;
            }
        };
        dfs();
        return res;
    }

    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

