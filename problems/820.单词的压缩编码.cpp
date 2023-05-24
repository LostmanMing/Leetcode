/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
struct Trie{
    bool is_End;
    Trie* next[26];
    Trie(){
        for(auto&n : next){
            n = nullptr;
        }
        is_End = false;
    }
    
};
class Solution {
public:
    void insert(Trie *root, const string &word, int pos){
        if(pos < 0){
            root->is_End = true;  // 如果已经遍历完整个单词，将当前节点标记为单词结尾
            return ;
        }
        if(!root->next[word[pos] - 'a']){
            root->next[word[pos] - 'a'] = new Trie();
        }
        root = root->next[word[pos] - 'a'];
        insert(root, word, pos - 1);  // 递归插入下一个字符
    }
    int count(Trie *root, int edgeCnt){
        bool is_leaf = true;
        int sum = 0;
        for(int i = 0; i < 26; i++){
            if(root->next[i]){
                is_leaf = false;
                sum += count(root->next[i], edgeCnt + 1);  // 递归计算子节点的边数
            }
        }
        if(is_leaf){
            return edgeCnt += 1;  // 如果是叶子节点，边数加一
        }
        return sum;
    }
    int minimumLengthEncoding(vector<string>& words) {
        root = new Trie();
        for(auto &word : words){
            insert(root, word, word.size() - 1);
        }
        return count(root,0);
    }
    Trie* root;
};
// @lc code=end

//题目
/**
 * 
 * 单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
 * words.length == indices.length
 * 助记字符串 s 以 '#' 字符结尾
 * 对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
 * 
 * 给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。
 * 
 * 示例 1：
 * 输入：words = ["time", "me", "bell"]
 * 输出：10
 * 解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
 * 
 * words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示
 * 
 * "time#bell#"
 * words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
 * words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示 
 * "time#bell#"
 * 
 * 
*/