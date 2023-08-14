/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }
    void dfs(vector<int>& nums,int start){
        if(start > nums.size()) return;
        res.push_back(path);
        for(int i = start;i < nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,i + 1);
            path.pop_back();
        }
    }
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

