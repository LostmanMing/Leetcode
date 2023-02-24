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
        vector<int> masks(length);              //建立 one-hot 编码
        for(int i = 0;i < length;i++){
            string word = words[i];
            for(int j = 0;j < word.size();j++){
                masks[i] |= 1 << (word[j] - 'a');
            }            
        }
        int res = 0;
        for(int i = 0;i < masks.size(); i++){
            for(int j = i+1;j < masks.size(); j++){
                if((masks[i] & masks[j]) == 0){
                    int tmp = words[i].size() * words[j].size();
                    if(tmp > res) res = tmp;
                }
            }
        }
        return res;
    }
};
// @lc code=end

