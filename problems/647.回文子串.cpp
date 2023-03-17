/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i,k = i;j >= 0 && k < n && s[j] == s[k];j--,k++){ // 中心1，中心为奇数
                ans++;
            }
            for(int j = i,k = i + 1;j >= 0 && k < n && s[j] == s[k];j--,k++){ // 中心2，中心为偶数
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
对于每一个字符，我们以其为中心，向两边扩散，
如果可以扩展，就增加答案。
因为回文串是对称的，所以我们可以从中心向两边扩展，
而不需要像普通的子串一样，从第一个字符开始枚举。

因为一个回文串的中心可能是一个字符，
也可能是两个相邻的字符，所以我们需要枚举所有可能的情况。
具体来说，我们从位置 i 和 i+1 出发，
分别向两边扩展。当 s[j] == s[k] 时，表示可以继续扩展，此时答案加一。

*/

//题目
/**
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 示例 1：
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
*/