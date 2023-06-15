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
        vector<bool> used(nums.size(), false);
        dfs(nums,used);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<bool> used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i = 0;i < nums.size();i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums,used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end
//题目
/**
 * 
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 示例 1：
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 全排列与组合的区别：
 *      全排列的大小是和原数组一样大
 *      全排列需要之前的数，不需要指定startIdx,直接从0开始
 *      全排列需要used数组，但不是为了去重，而是为了标志可用的下一个元素
 * 
 * 
 * 
 * 
*/
