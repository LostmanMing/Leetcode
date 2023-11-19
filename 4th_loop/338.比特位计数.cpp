/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i = 1;i <= n;i++){
            res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
};
// @lc code=end

