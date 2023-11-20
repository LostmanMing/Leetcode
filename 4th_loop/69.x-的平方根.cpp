/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
#include<cmath>
#define LL long long
class Solution {
public:
    int mySqrt(int x) {
        LL l = 0, r = x / 2 + 1;
        while(l <= r){
            LL m = l + (r - l) / 2;
            if(m * m == x) return m;
            else if(m * m > x){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return r;
    }
};
// @lc code=end

