/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sn = s.size();
        int pn = p.size();
        unordered_map<int,int> mps;
        unordered_map<int,int> mpp;
        for(auto& c : p){
            mpp[c]++;
        }
        for(int i = 0;i < pn;i++){
            mps[s[i]]++;
        }
        vector<int> res;
        int l = 0, r = pn - 1;
        while(r < sn){
            if(mps == mpp) res.push_back(l);
            if(--mps[s[l]] == 0) mps.erase(s[l]);
            l++;
            r++;
            mps[s[r]]++;
        }
        return res;
    }
};
// @lc code=end

