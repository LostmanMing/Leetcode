/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start

#include<vector>
using namespace std;
using LL = long long;
class Solution {
    int check(vector<int>& piles, LL m){
        LL cnt = 0;
        for(auto & p:piles){
            cnt += p / m + (p % m == 0? 0 : 1);
        }
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        LL l = 1;   //最小的香蕉数量
        LL r = 1;
        for(auto &p : piles) {
            r = max(r,static_cast<LL>(p));
        }
        while(l < r){
            LL m = (l + r) / 2;
            if(check(piles, m) > h) l = m + 1;
            else r = m;
        }
        return l;
    }
};
// @lc code=end

