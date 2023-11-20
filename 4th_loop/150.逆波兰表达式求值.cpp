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
        stack<int> s;
        for(auto & token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                if(token == "+"){
                    s.push(n1 + n2);
                }else if(token == "-"){
                    s.push(n1 - n2);
                }else if(token == "*"){
                    s.push(n1 * n2);
                }else if(token == "/"){
                    s.push(n1 / n2);
                }
            }else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
// @lc code=end

