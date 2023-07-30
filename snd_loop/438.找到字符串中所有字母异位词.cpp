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
        for(auto & c : p){
            mpp[c]++;
        }
        for(int i = 0;i <= np-1;i++){
            mps[s[i]]++;
        }
        vector<int> res;
        int left = 0, right = np-1;
        while(right < ns){
            if(mps == mpp) res.push_back(right - np+1);
            if(--mps[s[left]]==0) mps.erase(s[left]);
            left++;
            right++;
            mps[s[right]]++; 
        }
        return res;
    }
};
// @lc code=end

