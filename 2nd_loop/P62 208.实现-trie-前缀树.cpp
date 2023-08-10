/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include<string>
using namespace std;
class Trie {
public:
    Trie() {
        isEnd = false;
        for(auto & n : next) n = nullptr;
    }
    
    void insert(string word) {
        auto node = this;
        for(auto & c : word){
            if(!node->next[c-'a']){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        auto node = this;
        for(auto & c:word){
            if(!node->next[c-'a']) return false;
            node = node->next[c-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto node = this;
        for(auto & c:prefix){
            if(!node->next[c-'a']) return false;
            node = node->next[c-'a'];
        }
        return true;
    }
    bool isEnd;
    Trie * next[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

