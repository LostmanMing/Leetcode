/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 0;
        for(auto & p : piles){
            r = max(p,r);
        }
        while(l < r){
            int m = l + (r - l) / 2;
            if(count(piles,m) > h){
                l = m+1;
            }else{
                r = m;
            }
        }
        return l;
    }
    int count(vector<int>& piles, int k){
        int res = 0;
        for(int i = 0;i < piles.size();i++){
            res += piles[i] / k + (piles[i] % k == 0 ? 0:1);
        }
        return res;
    }
};
// @lc code=end

