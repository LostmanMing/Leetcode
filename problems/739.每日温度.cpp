/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;               //存放temperatures中每个元素的下标
        for(int i = 0;i < n;i++){   
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){//如果栈不为空且当前元素的温度高于栈顶元素的温度
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);  // 将当前元素下标入栈
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
 * 如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 示例 1:
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 示例 2:
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 
 * 
 * 
*/