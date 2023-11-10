/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        for(int i = 0;i < n;i++){
            string str = tokens[i];
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                if(str == "+") s.push(n1 + n2);
                if(str == "-") s.push(n1 - n2);
                if(str == "*") s.push(n1 * n2);
                if(str == "/") s.push(n1 / n2);
            }else{
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};
// @lc code=end

