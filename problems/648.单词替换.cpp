/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    struct Trie{
        bool is_End;      // 标记当前节点是否为单词结尾
        Trie *next[26];   // 子节点数组，用于存储下一个字符的指针
        Trie(){
            is_End = false;
            for(auto & n : next){n = nullptr;}  // 初始化子节点数组为空指针
        }
    } *tr;   // Trie 根节点指针

     // 插入单词到 Trie 树
    void insert(string word){
        auto p  = tr;  // 从根节点开始
        for(auto & c : word){
            if(!p->next[c - 'a']){   // 如果当前字符的子节点不存在
                p->next[c - 'a'] = new Trie();  // 创建新的子节点
            }
            p = p->next[c - 'a'];// 移动到下一个子节点
        }
        p->is_End = true;// 标记单词结尾
    }

    // 搜索 Trie 树中是否有当前单词的词根
    string search(string word){
        auto p = tr;  // 从根节点开始
        string res = "";  // 存储搜索结果
        for(auto &c : word){
            if(p->is_End){
                return res;    // 如果当前节点为词根结尾，返回搜索结果
            }
            if(!p->next[c - 'a']){  // 如果当前字符的子节点不存在，返回空字符串，表示未找到匹配词根
                return "";
            }
            res += c;  // 将当前字符添加到搜索结果中
            p = p->next[c - 'a'];  // 移动到下一个子节点
        }
        return res;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        tr = new Trie();
        for(auto &d : dictionary){
            insert(d);   // 将字典中的词根插入 Trie 树中
        }
        stringstream ss(sentence);   // 使用 stringstream 对句子进行分词
        string word;
        string res;
        while(ss >> word){
            string ret = search(word);  // 在 Trie 树中搜索当前单词词根
            if(ret == ""){
                res += word + ' ';  // 如果未找到匹配的词根，则将原单词添加到结果中
            }else{
                res += ret + ' '; // 如果找到匹配的词根，则将用词根代替单词
            }
        }
        res.pop_back();  // 去除结果末尾的空格
        return res;  // 返回替换前缀后的句子
    }
};
// @lc code=end

//题目
/**
 * 在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。
 * 例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
 * 
 * 现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。
 * 如果继承词有许多可以形成它的词根，则用最短的词根替换它。
 * 
 * 你需要输出替换之后的句子。
 * 
 * 示例 1：
 * 
 * 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
 * 输出："the cat was rat by the bat"
 * 
 * 
 * 
 * 
 * 
*/
