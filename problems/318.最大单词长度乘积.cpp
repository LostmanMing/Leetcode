/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);   // 建立每个单词的 one-hot 编码，masks中的每个元素代表一个单词的编码,即有这个字母为1，没有为0
        for(int i = 0;i < length;i++){
            string word = words[i];
            for(int j = 0;j < word.size();j++){  // 对于每个单词，遍历其中的每个字符，将该字符的one-hot编码加入masks[i]中
                masks[i] |= 1 << (word[j] - 'a');
            }            
        }
        int res = 0;
        for(int i = 0;i < masks.size(); i++){// 遍历每个单词的 one-hot 编码
            for(int j = i+1;j < masks.size(); j++){// 遍历其他单词的 one-hot 编码
                if((masks[i] & masks[j]) == 0){
                    int tmp = words[i].size() * words[j].size();// 如果两个单词的 one-hot 编码没有重复的位置，则它们的乘积就是两个单词的长度之积
                    if(tmp > res) res = tmp;
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*

具体来说，假设当前处理的是第i个单词，第j个字母，那么word[j] - 'a'会得到当前字母相对于字符'a'的偏移量，
比如'b' - 'a'就等于1，表示字母'b'在one-hot编码的第1位。然后将1左移偏移量位，得到该字母对应的one-hot编码。
最后将这个one-hot编码和masks[i]进行按位或操作，
就可以将该字母的one-hot编码加入到masks[i]中，从而实现了对当前单词的one-hot编码的构建。



*/