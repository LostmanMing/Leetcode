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
    vector<vector<int>> res;
    void dfs(vector<int> nums,vector<int>&path,int start){
        res.push_back(path);
        for(int i = start;i < nums.size();i++){
            path.push_back(nums[i]);// 将当前数字添加到路径中
            dfs(nums,path,i+1);  // 递归搜索下一层，起始位置为 i+1
            path.pop_back();   // 回溯，将当前数字从路径中删除,重要步骤。
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums,path,0);
        return res;
    }
};
// @lc code=end

//题目
/**
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 示例 1：
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 */