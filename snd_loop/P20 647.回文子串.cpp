// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

// 回文字符串 是正着读和倒过来读一样的字符串。

// 子字符串 是字符串中的由连续字符组成的一个序列。

// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

// 示例 1：

// 输入：s = "abc"
// 输出：3
// 解释：三个回文子串: "a", "b", "c"
// 示例 2：

// 输入：s = "aaa"
// 输出：6
// 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

// 提示：

// 1 <= s.length <= 1000
// s 由小写英文字母组成



// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem647.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int l = i,r = i;l >= 0 && r < n;l--,r++){
                if(s[l] == s[r]) res++;
                else break;
            }
            for(int l = i,r = i + 1;l >= 0 && r < n;l--,r++){
                if(s[l] == s[r]) res++;
                else break;
            }
        }
        return res;
    }
};
// @lc code=end

