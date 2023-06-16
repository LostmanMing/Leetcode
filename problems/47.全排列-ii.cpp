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
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,used);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i = 0;i < nums.size();i++){
            if(used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1])) continue; //去重操作
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

//有重复元素的全排列
/**
 * 
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 示例 1：
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 * 
 * 
 * 对比不含重复元素的全排列，需要多一个去重的条件，先将原数组排序，再看前一个元素是否和现在一样，并且是否已经被使用过
 * 
 * 
 * 
 * 
 * 
*/