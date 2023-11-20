/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> mp;
        vector<string> res;
        for(int i = 0;i < order.size();i++){
            mp[order[i]] = 'a' + i;
        }
        for(auto& word : words){
            string str = "";
            for(auto c : word){
                str.push_back(mp[c]);
            }
            res.push_back(str);
        }
        return is_sorted(res.begin(),res.end());
    }
};
// @lc code=end

