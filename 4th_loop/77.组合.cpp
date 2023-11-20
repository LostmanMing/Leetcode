/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        function<void(int)> dfs = [&](int start){
            if(start > n){
                return;
            }
            if(path.size() == k){
                res.push_back(path);
            }
            for(int i = start;i < n;i++){
                path.push_back(i+1);
                dfs(i+1);
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }

private: 
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end

