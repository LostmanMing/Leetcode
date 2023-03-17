/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    bool check(const string& s, int left ,int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else{
                return check(s,left,right - 1) || check(s, left + 1,right);
            } 
        }
        return true;
    }
};
// @lc code=end

//题目
/**
 * 给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。
 * 
 * 示例 1
 * 输入: s = "aba"
 * 输出: true
 * 
 * 示例 2:
 * 输入: s = "abca"
 * 输出: true
 * 解释: 可以删除 "c" 字符 或者 "b" 字符
 * 
 * 
*/