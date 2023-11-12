/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        dfs(n,1);
        return res;
    }
    void dfs(int n, int start){
        if(path.size() == k){
            res.push_back(path);
            return ;
        }

        for(int i = start;i <= n;i++){
            path.push_back(i);
            dfs(n,i+1);
            path.pop_back();
        }

    }
    int k;
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

