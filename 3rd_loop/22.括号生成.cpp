/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs(0,0);
        return res;
    }

    void dfs(int lc, int rc){
        if(lc == n && rc == n){
            res.push_back(path);
            return ;
        }

        if(lc > n || rc > lc) return ;

        for(int i = 0;i < 2;i++){
            int nlc = i == 0 ? lc + 1 : lc;
            int nrc = i == 1 ? rc + 1 : rc;
            path.push_back(str[i]);
            dfs(nlc,nrc);
            path.pop_back();
        }
    }

    int n;
    vector<char> str{'(',')'};
    string path = "";
    vector<string> res;
};
// @lc code=end

