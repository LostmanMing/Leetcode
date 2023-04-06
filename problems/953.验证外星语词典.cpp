/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i = 0; i < order.size();i++){
            map[order[i]] = i;
        }
        vector<string> decrypt;         //保存转换后的单词
        for(auto & word : words){
            string decrypt_word;
            for(auto & w : word){                //将单词转为字典序
                decrypt_word += ('a' + map[w]);
            }
            decrypt.push_back(decrypt_word);
        }
        return is_sorted(decrypt.begin(),decrypt.end());  //判断是否以字典序排序
    }
};
// @lc code=end



//题目
/**
 * 
 * 某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
 * 
 * 给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。
 * 
 * 示例 1：
 * 输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * 输出：true
 * 解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/