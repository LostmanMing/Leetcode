

/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
#include<vector>
#include<string>
#include<functional>
using namespace std;
class Trie{
public:
    Trie(): isEnd(false){
        for(auto & n: next) n = nullptr;
    }
    void insert(string str){
        auto node = this;
        for(auto & c : str){
            if(!node->next[c-'a']){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    Trie* next[26];
    bool isEnd;

};
class MagicDictionary {
public:

    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& str: dictionary){
            root->insert(str);
        }
    }
    
    bool search(string searchWord) {
        function<bool(Trie*,string,int,int)> dfs = [&](Trie*root, string str,int idx, int edit) -> bool{
            if(!root){
                return false;
            }
            if(idx == str.size() && edit == 1 && root->isEnd) return true;
            if(idx < str.size() && edit <= 1){
                bool res = false;
                for(int i = 0;i < 26 && !res;i++){
                    int new_edit = (str[idx]=='a'+i) ? edit : edit + 1;
                    res = dfs(root->next[i],str,idx+1,new_edit); 
                }
                return res;
            }
            return false;
        };
        return dfs(root,searchWord,0,0);
    }
    Trie* root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

