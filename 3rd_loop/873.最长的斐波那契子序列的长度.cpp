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
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++){
            mp[arr[i]] = i;
        }
        int res = 0;
        vector<vector<int>> dp(n,vector<int>(n,2));
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int dis = arr[j] - arr[i];
                if(dis >= arr[i]) break;
                if(mp.count(dis)){
                    dp[i][j] = dp[mp[dis]][i] + 1;
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

