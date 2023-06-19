// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

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
        dfs("",0,0);
        return res;
    }
    void dfs(string str, int lc, int rc){
        if(lc == n && n == rc ){    //成功返回条件
            res.push_back(str);
            return ;
        }
        if(lc < rc || lc > n)       //失败返回条件
            return;
        dfs(str+"(", lc + 1,rc);    //递归
        dfs(str+")", lc ,rc + 1);   //递归
    }
    int n;
    vector<string> res;
};
// @lc code=end
//题目
/**
 * 
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合
 * 
 * 示例 1：
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 示例 2：
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
*/
