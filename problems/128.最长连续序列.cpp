/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        for(auto& i:nums){
            uf[i] = i;
            cnt[i] = 1;
        }
        int res = 1;
        for(auto& i: nums){
            if(uf.count(i + 1)){
                res = max(res, join(i,i+1));    
            }
        }
        return res;
    }
private:
    int find(int x){
        return x == uf[x] ? x : uf[x] = find(uf[x]);
    }
    int join(int u,int v){
        u = find(u);
        v = find(v);
        if(u == v) return cnt[u];
        uf[v] = u;
        cnt[u] += cnt[v];
        return cnt[u];
    }
    bool same(int u,int v){
        u = find(u);
        v = find(v);
        return u==v;
    }
    unordered_map<int,int> uf, cnt;
};
// @lc code=end

//哈希表解法
// int longestConsecutive(vector<int>& nums) {
//     int n = nums.size();
//     unordered_set<int> ht(nums.begin(),nums.end());
//     int res = 0;
//     for(auto & i : nums){
//         if(ht.count(i-1)) continue;
//         int cnt = 1;
//         while(ht.count(i+1)){
//             cnt++;
//             i++;
//         }
//         res = max(res, cnt);
//     }
//     return res;
// }