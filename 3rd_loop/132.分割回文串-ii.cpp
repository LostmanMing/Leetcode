/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include<string>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> is_hw(n,vector<bool>(n,false));
        for(int i = n - 1;i >= 0;i--){
            for(int j = i;j < n;j++){
                if(s[i] == s[j] && (j - i <= 1 || is_hw[i+1][j-1])){
                    is_hw[i][j] = true;
                }
            }
        }

        vector<int> dp(n,INT_MAX);
        for(int i = 0;i < n;i++){
            if(is_hw[0][i]){
                dp[i] = 0;
            }
            for(int j = 0;j < i;j++){
                if(is_hw[j+1][i]){
                    dp[i] = min(dp[i],dp[j] + 1);
                }
            }
        }
        return dp[n-1];

    }
};
// @lc code=end

