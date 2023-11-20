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
        for(int i = 0;i < 26;i++) next[i] = nullptr;
        is_end = false;
    }
    
    void insert(string word) {
        auto node = this;
        for(auto & w : word){
            if(!node->next[w-'a']){
                node->next[w-'a'] = new Trie();
            }
            node = node->next[w-'a'];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        auto node = this;
        for(auto & w: word){
            if(!node->next[w-'a']) return false;
            node = node->next[w-'a'];
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        auto node = this;
        for(auto & w : prefix){
            if(!node->next[w-'a']) return false;
            node = node->next[w-'a'];
        }
        return true;
    }
private:
    Trie* next[26];
    bool is_end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

