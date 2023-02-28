/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <climits>
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int num = x % 10;
            x /= 10;
            //如果当前ans值除10大于整数最大值或者小于整数最小值，或者等于最大最小值时，
            //那么ans = ans * 10 + num;就会超出整形范围。
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && num > 7)) return 0;
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && num < -8)) return 0;
            ans = ans * 10 + num;
        }
        return ans;
    }
};
// @lc code=end

