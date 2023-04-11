/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> table(26,0);
        for(auto &c : s){
            table[c - 'a']++;
        }
        for(auto &c : t){
            if(--table[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

//题目 有效的字母异位词
/**
 * 
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 示例 1:
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
*/

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         return unordered_multiset(begin(s), end(s)) == unordered_multiset(begin(t), end(t));
//     }
// };