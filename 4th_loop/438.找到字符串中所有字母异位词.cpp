/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np = p.size();

        unordered_map<char,int> mps;
        unordered_map<char,int> mpp;

        for(int i = 0;i < np;i++){
            mps[s[i]]++;
            mpp[p[i]]++;
        }

        int l = 0, r = np-1;
        vector<int> res;
        while(r < ns){
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

