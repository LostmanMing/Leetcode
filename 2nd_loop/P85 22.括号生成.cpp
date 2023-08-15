// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：

// 输入：n = 1
// 输出：["()"]
 

// 提示：

// 1 <= n <= 8

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<string>
#include<functional>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> lr{'(',')'};
        function<void(int,int)> dfs = [&]( int lc, int rc){
            if(lc < rc || lc > n){
                return ;
            }
            if(lc == n && rc == n){
                res.push_back(str);
            }
            for(int i = 0;i < 2;i++){
                int nlc = i == 0 ? lc + 1 : lc;
                int nlr = i == 1 ? rc + 1 : rc;
                str.push_back(lr[i]);
                dfs(nlc,nlr);
                str.pop_back();
            }
        };
        dfs(0,0);
        return res;
    }
    string str = "";
    vector<string> res;
};
// @lc code=end

