/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include <climits> 
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend < 0 && divisor >0) || (dividend > 0 && divisor < 0);
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        int ans = 0;
        while(dividend <= divisor){
            int value = divisor;
            int k = 1;
            while(value >= 0xc0000000 && dividend <= value + value){
                value += value;
                if(k > (INT_MAX >> 1)) return INT_MIN;
                k += k;
            }
            dividend -= value;
            ans += k;
        }
        return sign? -ans:ans;
    }
};
// @lc code=end

