/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<functional>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> kh{'(',')'};
        function<void(int,int)> dfs= [&](int lc, int rc){
            if(rc > lc || lc > n){
                return ;
            }
            if(lc == n && rc == n){
                res.push_back(path);
                return ;
            }
            for(int i = 0;i < 2;i++){
                int nlc = i == 0 ? lc + 1 : lc;
                int nrc = i == 1 ? rc + 1 : rc;
                path.push_back(kh[i]);
                dfs(nlc,nrc);
                path.pop_back();
            }
        };
        dfs(0,0);
        return res;
    }
    vector<string> res;
    string path;
};
// @lc code=end

