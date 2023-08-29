// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

// 题目数据保证答案符合 32 位带符号整数范围。

 

// 示例 1：

// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// rabbbit
// rabbbit
// rabbbit
// 示例 2：

// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// 提示：

// 1 <= s.length, t.length <= 1000
// s 和 t 由英文字母组成


/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<uint64_t>> dp(n+1,vector<uint64_t>(m+1,0)); //以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]
        for(int i = 0;i <= n;i++){
            dp[i][0] = 1;
        }
        for(int j = 1;j <=m;j++){
            dp[0][j] = 0;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];  
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

