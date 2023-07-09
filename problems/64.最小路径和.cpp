// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n1 = grid.size(),n2 = grid[0].size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        dp[0][0] = grid[0][0];
        for(int i = 1;i < n1;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1;i < n2;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1;i < n1;i++){
            for(int j = 1;j < n2;j++){
                dp[i][j]=grid[i][j] + min( dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n1-1][n2-1];
    }
};
// @lc code=end

//题目
/**
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 示例 1：
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 * 
 * 
 * 
*/