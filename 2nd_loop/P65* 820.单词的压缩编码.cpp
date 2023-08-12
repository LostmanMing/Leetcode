/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Trie{
public:
    Trie(): isEnd(false),next(26,nullptr){}

    void insert(string str){
        auto node = this;
        reverse(str.begin(),str.end());
        for(auto& s : str){
            if(!node->next[s-'a']) node->next[s-'a'] = new Trie();
            node = node->next[s-'a'];
        }
        node->isEnd = true;
    }
    bool isEnd;
    vector<Trie*> next;
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* root = new Trie();
        for(auto& word : words){
            root->insert(word);
        }
        return count(root,0);
    }
    int count(Trie* root, int cnt){
        bool isEdge = true;
        int res = 0;
        for(int i = 0;i < 26;i++){
            if(root->next[i]){
                isEdge = false;
                res += count(root->next[i],cnt+1);
            }
        }
        //当前节点没有孩子时返回值，递归内返回值
        if(isEdge){
            return cnt+1;
        }
        //有孩子时返回值，最外部返回值
        return res;
    }
};
// @lc code=end

