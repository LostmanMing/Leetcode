/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        path.resize(N,string(N,'.'));
        dfs(0);
        return res;
    }

    void dfs(int row){
        if(row == N){
            res.push_back(path);
            return ;
        }

        for(int i = 0;i < N;i++){
            if(is_valid(row,i)){
                path[row][i] = 'Q';
                dfs(row+1);
                path[row][i] = '.';
            }
        }
    }

    bool is_valid(int row,int col){
        for(int i = 0;i < row;i++){
            if(path[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row -1,j = col-1;i >= 0 && j >= 0;i--,j--){
            if(path[i][j] =='Q') return false;
        }
        for(int i = row - 1,j = col+1;i >= 0 && j < N;i--,j++){
            if(path[i][j] =='Q') return false;
        }
        return true;
    }

    int N;
    vector<string> path;
    vector<vector<string>> res; 
};
// @lc code=end

