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
        int n = asteroids.size();
        vector<int> s;
        for(int i = 0;i < n;i++){
            while(!s.empty() && s.back() > 0 && asteroids[i] < 0){
                int n = s.back() + asteroids[i];
                if(n < 0){
                    s.pop_back();
                }else if(n > 0){
                    asteroids[i] = 0;
                }else{
                    s.pop_back();
                    asteroids[i] = 0;
                }
            }
            if(asteroids[i] != 0) s.push_back(asteroids[i]);
        }
        return s;
    }
};
// @lc code=end

