/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string s_sub;
        for (auto &&i : s){
            if(isalnum(i)) s_sub += tolower(i);  //判断是否是字符或者数字，然后将字符转小写重新保存
        }
        int n = s_sub.size();
        int left = 0, right = n - 1;
        while(left < right){
            if(s_sub[left] == s_sub[right]){    //双指针 对撞指针
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



//题目
/**
 * 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。
 * 则可以认为该短语是一个 回文串 。
 * 字母和数字都属于字母数字字符。
 * 
 * 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
 * 
 * 示例 1：
 * 
 * 输入: s = "A man, a plan, a canal: Panama"
 * 
 * 输出：true
 * 
 * 解释："amanaplanacanalpanama" 是回文串。
 * 
*/