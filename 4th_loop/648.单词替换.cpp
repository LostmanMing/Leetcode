/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Trie{
public:
    Trie() : next(vector<Trie*>(26,nullptr)),is_end(false){}

    void insert(string word){
        auto node = this;
        for(auto& c : word){
            if(!node->next[c-'a']){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->is_end = true;
    }

    string search(string word){
        string res = "";
        auto node = this;
        for(auto& c : word){
            if(!node->next[c-'a']) return word;
            res.push_back(c);
            if(node->next[c-'a']->is_end) return res;
            node = node->next[c-'a'];
        }
        return res;
    }

private:
    vector<Trie*> next;
    bool is_end;
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for(auto & d : dictionary){
            root->insert(d);
        }
        string res = "";
        string word;
        stringstream ss(sentence);
        while(ss >> word){
            word = root->search(word);
            res += word + " ";
        }
        res.pop_back();
        return res;
    }

};
// @lc code=end

