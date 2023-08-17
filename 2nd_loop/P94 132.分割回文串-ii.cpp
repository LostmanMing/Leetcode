// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

// 返回符合要求的 最少分割次数 。

 

// 示例 1：

// 输入：s = "aab"
// 输出：1
// 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 示例 2：

// 输入：s = "a"
// 输出：0
// 示例 3：

// 输入：s = "ab"
// 输出：1
 

// 提示：

// 1 <= s.length <= 2000
// s 仅由小写英文字母组成


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
        // 当s[i]与s[j]相等时，这就复杂一些了，有如下三种情况
        // 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
        // 情况二：下标i 与 j相差为1，例如aa，也是回文子串
        // 情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否为true。
        for(int i = n-1 ;i >= 0;i--){
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
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

