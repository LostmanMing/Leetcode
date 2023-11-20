/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include<vector>
#include<string>
#include<functional>
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
                string substr = s.substr(start,i-start+1);
                if(is_hw(substr)){
                    path.push_back(substr);
                }else{
                    continue;
                }
                dfs(i+1);
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }
    bool is_hw(string s){
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> res;
    vector<string> path;
};
// @lc code=end

