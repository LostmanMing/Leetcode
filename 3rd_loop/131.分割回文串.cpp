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
        dfs(s,0);
        return res;
    }

    bool is_hw(string& s){
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(string& s,int start){
        if(start >= s.size()){
            res.push_back(path);
            return ;
        }

        for(int i = start;i < s.size();i++){
            string sub_str = s.substr(start, i - start + 1);
            if(is_hw(sub_str)){
                path.push_back(sub_str);
                dfs(s,i+1);
                path.pop_back();
            }else continue;
        }
    }

    vector<string> path;
    vector<vector<string>> res;
};
// @lc code=end

