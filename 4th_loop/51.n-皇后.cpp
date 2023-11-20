/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include<vector>
#include<string>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        path.resize(n,string(n,'.'));
        function<void(int)> dfs = [&](int row){
            if(row == n){
                res.push_back(path);
                return ;
            }
            for(int i = 0;i < n;i++){
                if(isVaild(row,i)){
                    path[row][i] = 'Q';
                    dfs(row + 1);
                    path[row][i] = '.';
                }else continue;
            }
        };
        dfs(0);
        return res;
    }
    bool isVaild(int row, int col){
        for(int i = 0;i < row;i++){
            if(path[i][col] == 'Q') return false;
        }
        for(int i = row-1,j = col-1;i >= 0 && j >= 0;i--,j--){
            if(path[i][j] == 'Q') return false;
        }
        for(int i = row-1,j = col+1;i >= 0 && j < n;i--,j++){
            if(path[i][j] == 'Q') return false;
        }
        return true;
    }
    int n;
    vector<vector<string>> res;
    vector<string> path;
};
// @lc code=end

