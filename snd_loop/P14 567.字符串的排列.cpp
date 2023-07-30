// 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

// 换句话说，s1 的排列之一是 s2 的 子串 。

 

// 示例 1：

// 输入：s1 = "ab" s2 = "eidbaooo"
// 输出：true
// 解释：s2 包含 s1 的排列之一 ("ba").
// 示例 2：

// 输入：s1= "ab" s2 = "eidboaoo"
// 输出：false
 

// 提示：

// 1 <= s1.length, s2.length <= 104
// s1 和 s2 仅包含小写字母

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int left = 0,right = n1-1;
        for(auto & s:s1){
            mp1[s]++;
        }
        for(int i = 0;i <= right;i++){
            mp2[s2[i]]++;
        }
        while(right < n2){
            if(mp1 == mp2) return true;
            if(--mp2[s2[left]] == 0) mp2.erase(s2[left]);
            left++;
            right++;
            mp2[s2[right]]++;
        }
        return false;
    }
};
// @lc code=end

