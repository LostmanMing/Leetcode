// 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

 

// 示例 1：


// 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
// 输出：4 
// 解释：最长递增路径为 [1, 2, 6, 9]。
// 示例 2：


// 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
// 输出：4 
// 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 示例 3：

// 输入：matrix = [[1]]
// 输出：1
 

// 提示：

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1

/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        vector<vector<int>> dir{{0,-1},{0,1},{1,0},{-1,0}};

        function<int(int,int)> dfs = [&](int x, int y) ->int{
            if(dp[x][y]!=0) return dp[x][y];
            
            int len = 1;
            for(int i = 0;i < 4;i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] > matrix[x][y]){
                    len = max(len,dfs(nx,ny) + 1);
                }

            }
            dp[x][y] = len;
            return dp[x][y];
        };

        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res = max(res,dfs(i,j));
            }
        }
        return res;
    }
};
// @lc code=end

