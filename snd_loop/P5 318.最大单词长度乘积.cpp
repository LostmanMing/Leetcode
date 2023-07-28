// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem318.h"

using namespace std;
// @before-stub-for-debug-end

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
        int n = words.size();
        vector<int> mask(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < words[i].size();j++){
                mask[i] |= 1 << (words[i][j] - 'a');
            }
        }
        int res = 0;
        for(int i = 0;i < mask.size();i++){
            for(int j = i + 1;j < mask.size();j++){
                if((mask[i] & mask[j]) == 0){
                    int n = words[i].size() * words[j].size();
                    res = max(res, n);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。

// 示例 1：

// 输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// 输出：16 
// 解释：这两个单词为 "abcw", "xtfn"。
// 示例 2：

// 输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
// 输出：4 
// 解释：这两个单词为 "ab", "cd"。
// 示例 3：

// 输入：words = ["a","aa","aaa","aaaa"]
// 输出：0 
// 解释：不存在这样的两个单词。
 

// 提示：

// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] 仅包含小写字母