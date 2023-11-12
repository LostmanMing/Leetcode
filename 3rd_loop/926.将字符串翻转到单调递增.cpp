/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        if(s[0] == '0'){
            dp[0][1] = 1;
        }else{
            dp[0][0] = 1;
        }

        for(int i = 1;i < n;i++){
            if(s[i] == '0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0]+1,dp[i-1][1]+1);
            }else{
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = min(dp[i-1][1],dp[i-1][0]);
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
        
    }
};
// @lc code=end

