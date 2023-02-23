/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i = 0; i <= n;i++){
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
// @lc code=end

/*
        for(int i = 0; i <= n;i++){
            if(i % 2 == 1) res[i] = res[i - 1] + 1;
            if(i % 2 == 0) res[i] = res[i / 2];
        }
        ========>
        for(int i = 0; i <= n;i++){
            res[i] = res[i / 2] + i % 2; // i / 2  ==> i >> 1     i % 2 ==> i & 1;
        }
*/