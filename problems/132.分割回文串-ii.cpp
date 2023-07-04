/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> is_p(n,vector<bool>(n,false));    //判断i-j范围内子串是否回文
        for(int i = n - 1;i>=0;i--){
            for(int j = 0;j < n;j++){
                if(s[i]==s[j] && (j-i<=1 || is_p[i+1][j-1]==true)){
                    is_p[i][j] = true;
                }
            }
        }
        vector<int> dp(n);   //dp表示 0 - i范围内切割回文的最小次数
        for(int i = 0;i < n;i++) dp[i] = i;   //初始化，照大了初始化，因为遍历时会比较最小
        for(int i = 0;i < n;i++){   
            if(is_p[0][i]){        //如果0-i是回文则不用切割
                dp[i] = 0;
                continue;
            }
            for(int j = 0;j < i;j++){
                if(is_p[j+1][i]){     //如果j后面的一段是回文，则在j处切割一次，加上j之前的切割次数
                    dp[i] = min(dp[j] + 1,dp[i]);    
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

