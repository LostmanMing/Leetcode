/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());  //使用set查找更快
        if(wordset.find(endWord) == wordset.end()) return 0;
        unordered_map<string,int> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert({beginWord,1});
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int path = visited[word];
            for(int i = 0;i < word.size();i++){
                string nword = word;
                for(int j = 0;j < 26;j++){
                    nword[i] = j + 'a';
                    if(nword == endWord) return path + 1;
                    if(wordset.find(nword) != wordset.end() && visited.find(nword) == visited.end()){
                        q.push(nword);
                        visited.insert({nword,path+1});
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

//题目
/**
 * 
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
 * 
 * 示例 1：
 * 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 * 
 * 
 * 
 * 
 * 
 * 
*/