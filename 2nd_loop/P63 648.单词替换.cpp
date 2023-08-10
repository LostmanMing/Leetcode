// 在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

// 现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

// 你需要输出替换之后的句子。

 

// 示例 1：

// 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// 输出："the cat was rat by the bat"
// 示例 2：

// 输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// 输出："a a b c"
 

// 提示：

// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] 仅由小写字母组成。
// 1 <= sentence.length <= 10^6
// sentence 仅由小写字母和空格组成。
// sentence 中单词的总量在范围 [1, 1000] 内。
// sentence 中每个单词的长度在范围 [1, 1000] 内。
// sentence 中单词之间由一个空格隔开。
// sentence 没有前导或尾随空格。

/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
#include<vector>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    class Trie{
    public:
        Trie():isEnd(false){
            for(auto& n:next) n = nullptr;
        }
        void insert(string str){
            auto node = this;
            for(auto & s : str){
                if(!node->next[s-'a']){
                    node->next[s-'a'] = new Trie();
                }
                node = node->next[s-'a'];
            }
            node->isEnd = true;
        }

        string search(string& str){
            auto node = this;
            string res = "";
            for(auto& s : str){
                if(!node->next[s-'a']) return str;
                res.push_back(s);
                if(node->next[s-'a']->isEnd) return res;
                node = node->next[s-'a'];
            }
            return res;
        }
    private:
        bool isEnd;
        Trie* next[26];


    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        auto head = root;
        for(auto& dic : dictionary){
            root->insert(dic);
        }
        string res;
        stringstream ss(sentence);
        string word;
        while(ss >> word){
            word = head->search(word);
            res += word + " ";
            word.clear();
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

