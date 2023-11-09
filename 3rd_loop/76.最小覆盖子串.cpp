/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        int vaild = 0;
        int len = sn+1;
        int start = 0;
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;
        for(auto & c : t){
            t_map[c]++;
        }
        int l = 0, r = 0;
        while(r < sn){
            if(t_map.count(s[r])){
                s_map[s[r]]++;
                if(s_map[s[r]] == t_map[s[r]]){
                    vaild++;
                }
            }
            while(vaild == t_map.size()){
                if(len > r - l + 1){
                    len = r - l + 1;
                    start = l;
                }
                if(t_map.count(s[l])){
                    if(t_map[s[l]] == s_map[s[l]]) vaild--;
                    s_map[s[l]]--;
                }
                l++;
            }
            r++;
        }
        return len == sn + 1 ? "" : s.substr(start,len);
    }
};
// @lc code=end

