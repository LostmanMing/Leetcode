/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> map;   //使用hash表保存正序字符串和它的所有异位字符串
        for (auto &str : strs){
            string s = str;
            sort(str.begin(),str.end());
            map[str].push_back(s);
        }
        vector<vector<string>> res;    
        for (auto &m : map){
            res.push_back(m.second);
        }
        
        return res;
    }
};
// @lc code=end

//题目
/**
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 * 
 * 
 * 示例 1:
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
*/