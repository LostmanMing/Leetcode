/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include <vector>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {      //前缀和矩阵   思路看题解
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        sums.resize(n+1, vector<int>(m+1,0));
        for(int i = 1; i <= n;i++){
            for(int j =1; j <= m; j++){
                sums[i][j] = matrix[i-1][j-1] + sums[i][j-1] + sums[i-1][j] - sums[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
    }
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

