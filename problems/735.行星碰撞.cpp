/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    // 给定一个代表小行星的整数数组 asteroids，正数表示向右移动的小行星，负数表示向左移动的小行星。
    // 返回小行星碰撞后剩下的小行星。如果两颗同向的小行星相遇，两颗都会消失。
    // 如果两颗异向的小行星相遇，较小的一颗会消失，较大的一颗会留下。
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // 用于模拟小行星碰撞的栈
        for(auto& a : asteroids){ // 遍历所有小行星
            while(!st.empty() && st.back() > 0 && a < 0){  // 模拟小行星碰撞
                int cur = a + st.back();  // 计算碰撞后的大小关系
                if(cur > 0){   // 右侧小行星更大，左侧小行星消失
                    a = 0;
                }else if(cur == 0){  // 两颗小行星相等，都消失
                    a = 0;
                    st.pop_back();   // 左侧小行星更大，右侧小行星消失
                } else{
                    st.pop_back();  // 如果该小行星没有被消失，将其加入栈中
                } 
            }
            if(a != 0){
                st.push_back(a);
            }
        }
        return st;  // 返回剩下的小行星
    }
};
// @lc code=end


//题目
/**
 * 给定一个整数数组 asteroids，表示在同一行的行星。
 * 
 * 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。
 * 每一颗行星以相同的速度移动。
 * 
 * 找出碰撞后剩下的所有行星。
 * 碰撞规则：两个行星相互碰撞，较小的行星会爆炸。
 * 如果两颗行星大小相同，则两颗行星都会爆炸。
 * 两颗移动方向相同的行星，永远不会发生碰撞。
 * 
 * 
 * 示例 1：
 * 输入：asteroids = [5,10,-5]
 * 输出：[5,10]
 * 解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
 * 
 * 示例 2：
 * 输入：asteroids = [8,-8]
 * 输出：[]
 * 解释：8 和 -8 碰撞后，两者都发生爆炸。
 * 
 * 示例 3：
 * 输入：asteroids = [10,2,-5]
 * 输出：[10]
 * 解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
 * 
 * 
 * 
 * 
 * 
*/

