/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int cur_row = 0;
        bool go_down = false;
        string ans;
        vector<string> res(min(numRows, (int)s.size()));
        if(numRows == 1) return s;
        for (auto &c : s){
            res[cur_row] += c;
            if(cur_row == 0 || cur_row == numRows - 1){
                go_down = !go_down;
            }
            cur_row += go_down ? 1 : -1;
        }
        for (auto &s : res){
            ans += s;
        }
        return ans;
    }
};
// @lc code=end

