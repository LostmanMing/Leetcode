/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1,false));
        dp[0][0] = true;
        for(int i = 0;i <= n1;i++){
            for(int j = 0;j <= n2;j++){
                if(i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j]){
                    dp[i][j] = true;
                }
                if(j > 0 && s2[j-1] == se[i+j-1] && dp[i][j-1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

