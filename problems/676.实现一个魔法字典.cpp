/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Trie{
public:
    Trie() : is_End(false),next(26,nullptr){}
    void instert(string &word){
        auto node = this;    // 从根节点开始插入
        for(auto &c : word){
            if(!node->next[c - 'a']){
                node->next[c - 'a'] = new Trie();  // 如果下一个字符的指针为空，创建一个新的 Trie 节点
            }
            node = node->next[c - 'a'];  // 移动到下一个节点
        }
        node->is_End = true;
    }
    bool is_End;   // 标记当前节点是否为一个单词的结尾
    std::vector<Trie*> next;  // 存储下一个字符的指针数组，长度为26，每个索引表示一个小写字母
};
class MagicDictionary {
    bool dfs(Trie* root, string word, int idx, int edit){
        if(!root) return false;
        if(root->is_End && idx == word.size() && edit == 1) return true;  // 如果到达单词结尾，且只有一个字符编辑操作，返回 true,唯一出口
        if(idx < word.size() && edit <= 1){
            bool res = false;
            for(int i = 0; i < 26 && !res; i++) {
                int next_edit = (word[idx] - 'a' == i) ? edit : edit + 1; // 如果当前字符与 Trie 树中的字符相同，则不需要编辑，否则编辑次数加一
                res = dfs(root->next[i], word, idx + 1, next_edit);// 递归搜索下一个字符
            }
            return res;
        }
        return false;
    }
public:
    Trie *root;
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &d : dictionary){
            root->instert(d);
        }
    }
    
    bool search(string searchWord) {
        return dfs(root, searchWord, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

//题目
/**
 * 
 * 设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。 如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。
 * 
 * 实现 MagicDictionary 类：
 * MagicDictionary() 初始化对象
 * void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary 中的字符串互不相同
 * 
 * bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。
 * 
 * 示例：
 * 输入
 * 
 * ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
 * [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
 * 
 * 输出
 * [null, null, false, true, false, false]
 * 
 * 
 * 
 * 
 * 
 * 
*/