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
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie;
        for(auto & word : dictionary){
            root->insert(word);
        }
        string res;
        stringstream ss(sentence);
        string word;
        while(ss >> word){
            word = root->search(word);
            res += string(word+" ");
        }
        res.pop_back();
        return res;
    }

    class Trie{
    public:
        Trie() : is_end(false){
            for(int i = 0;i < 26;i++) next[i] = nullptr;
        }

        void insert(string word){
            auto node = this;
            for(auto c:word){
                if(!node->next[c-'a']){
                    node->next[c-'a'] = new Trie();
                }
                node = node->next[c-'a'];
            }
            node->is_end = true;
        }

        string search(string word){
            auto node = this;
            string res = "";
            for(auto c:word){
                if(!node->next[c-'a']){
                    return word;
                }
                res.push_back(c);
                if(node->next[c-'a']->is_end){
                    return res;
                }
                node = node->next[c-'a'];
            }
            return res;
        }
    private:
        bool is_end;
        Trie* next[26];
    };
};
// @lc code=end

