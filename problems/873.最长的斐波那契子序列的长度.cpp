/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            mp[arr[i]] = i;
        }
        vector<vector<int>> dp(n,vector<int>(n,2));// dp[i][j]表示如果i之前有数可以和ij满足斐波那契时的最长子序列长度
        int diff = 0;
        int ans = 0;
        for(int left = 0;left < n;left++){
            for(int right = left + 1;right < n;right++){
                diff = arr[right] - arr[left];   //左边界的值
                if(diff >= arr[left]) break;   //左边界值大于右边界
                if(mp.count(diff)){
                    int diff_idx = mp[diff];   //左边界索引
                    dp[left][right] = dp[diff_idx][left] + 1;  
                    ans = max(ans, dp[left][right]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

