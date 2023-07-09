// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<climits>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0] = triangle[0][0];
        for(int i = 1;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else if(j == i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else{
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        int res = INT_MAX;
        for(int i =0;i < n;i++){
            res = min(res,dp[n-1][i]);
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 
 * 
 * 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 * 
 * 示例 1：
 * 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * 输出：11
 * 解释：如下面简图所示：
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 
 * 
*/