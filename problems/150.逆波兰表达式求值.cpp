/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){    //是字符就从栈中取出两个数字进行相应的操作
                int after = st.top();
                st.pop();
                int pre = st.top();
                st.pop();
                if(t == "+"){
                    st.push(pre + after);
                }else if(t == "-"){
                    st.push(pre - after);
                }else if(t == "*"){
                    st.push(pre * after);
                }else if(t == "/"){
                    st.push(pre / after);
                }
            }else{
                st.push(stoi(t));       //是数字就入栈 
            }
        }
        return st.top();            
    }
};
// @lc code=end

//题目
/**
 * 
 * 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
 * 
 * 请你计算该表达式。返回一个表示表达式值的整数。
 * 
 * 注意：
 * 有效的算符为 '+'、'-'、'*' 和 '/' 。
 * 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
 * 两个整数之间的除法总是 向零截断 。
 * 表达式中不含除零运算。
 * 输入是一个根据逆波兰表示法表示的算术表达式。
 * 答案及所有中间计算结果可以用 32 位 整数表示。
 * 
 * 
 * 示例 1：
 * 输入：tokens = ["2","1","+","3","*"]
 * 输出：9
 * 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 * 
 * 
 * 
 * 
 * 
 * 
*/