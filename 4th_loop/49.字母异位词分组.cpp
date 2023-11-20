/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto &str : strs){
            string s = str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& m : mp){
            res.push_back(m.second);
        }
        return res;
    }
};
// @lc code=end

