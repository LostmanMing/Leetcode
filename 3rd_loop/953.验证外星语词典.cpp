/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> mp;
        for(int i = 0;i < order.size();i++){
            mp[order[i]] = 'a' + i;
        }

        vector<string> res;

        for(int i = 0;i < words.size();i++){
            string s = "";
            for(auto & w : words[i]){
                s.push_back(mp[w]);
            }
            res.push_back(s);
        }
        return is_sorted(res.begin(),res.end());
    }
};
// @lc code=end

