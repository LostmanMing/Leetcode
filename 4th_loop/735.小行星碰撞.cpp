/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 小行星碰撞
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(auto & a : asteroids){
            while(!s.empty() && s.back() > 0 && a < 0){
                int num = s.back() + a;
                if(num > 0){
                    a = 0;
                }else if(num < 0){
                    s.pop_back();
                }else{
                    s.pop_back();
                    a = 0;
                }
            }
            if(a!=0){
                s.push_back(a);
            }
        }
        return s;
    }
};
// @lc code=end

