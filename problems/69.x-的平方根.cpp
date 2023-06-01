/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
#include<algorithm>
#include<cmath>
using namespace std;
using LL = long long;
class Solution {
public:
    int mySqrt(int x) {
        LL l = 0;
        LL r = x / 2 + 1;
        while (l <= r){
            LL m = (l + r) / 2;
            LL res = m * m;
            if(res == x) return m;
            else if(res < x) l = m + 1;
            else r = m - 1;
        }
        return r;
        // return sqrt(x);
    }
};
// @lc code=end

