/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include<climits>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        bool sign = (dividend >0 && divisor < 0 ) || (dividend < 0 && divisor > 0);
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        int res = 0;
        while(dividend <= divisor){
            int value = divisor;
            int cnt = 1;
            while(value > dividend - value){
                value += value;
                cnt += cnt;
            }
            dividend -= value;
            res += cnt;
        }
        return sign ? -res : res;
    }
};
// @lc code=end

