// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return res;
    }
private:
    void dfs(int startIdx, string &s){
        if(startIdx >= s.size()){
            res.push_back(path);
            return ;
        }
        for(int i = startIdx;i < s.size();i++){
            string s_sub = s.substr(startIdx, i - startIdx + 1); // 得到子串
            if(is_hw(s_sub)){  //判断子串是否是回文，不是直接下一个循环
                path.push_back(s_sub);
            }else continue;
            dfs(i + 1,s);
            path.pop_back();
        }
    }
    bool is_hw(string s){
        int l = 0, r = s.size() - 1;
        while(l <= r){
            if(s[l] == s[r]){
                ++l;
                --r;
            }else return false;
        }
        return true;
    }
    vector<string> path;
    vector<vector<string>> res;
};
// @lc code=end

//题目
/**
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 示例 1：
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 
 * 
*/