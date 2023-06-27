// @before-stub-for-debug-begin
#include <vector>
#include <string>
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        else if (n==1)
        {
            return 1;
        }else if (n==2)
        {
            return 1;
        }
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
 
};
// @lc code=end

