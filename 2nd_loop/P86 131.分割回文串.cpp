// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 回文串 是正着读和反着读都一样的字符串。

 

// 示例 1：

// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
// 示例 2：

// 输入：s = "a"
// 输出：[["a"]]
 

// 提示：

// 1 <= s.length <= 16
// s 仅由小写英文字母组成


/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include<vector>
#include<functional>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        function<void(int)> dfs = [&](int start){
            if(start >= s.size()){
                res.push_back(path);
                return ;
            }
            for(int i = start;i < s.size();i++){
                string substr = s.substr(start, i - start + 1);
                if(is_hw(substr)){
                    path.push_back(substr);
                }else continue;
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }
    bool is_hw(string& str){
        int l = 0, r = str.size() - 1;
        while(l < r){
            if(str[l] != str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<string> path;
    vector<vector<string>> res;
};
// @lc code=end

