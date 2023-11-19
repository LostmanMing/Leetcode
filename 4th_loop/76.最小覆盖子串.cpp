/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size();
        int nt = t.size();

        int valid = 0;

        unordered_map<char,int> mpt;
        unordered_map<char,int> mps;
        for(auto & c : t){
            mpt[c]++;
        }
        
        int l = 0, r = 0;
        int start = 0, len = INT_MAX;;
        while(r < ns){
            mps[s[r]]++;
            if(mpt.count(s[r]) &&  mps[s[r]] == mpt[s[r]]) valid++;
            while(valid == mpt.size()){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    start = l;
                }
                if(mpt.count(s[l]) && mps[s[l]] == mpt[s[l]]){
                    valid--;
                }
                mps[s[l]]--;
                l++;
            }
            r++;
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
// @lc code=end

