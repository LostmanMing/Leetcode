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
    bool checkInclusion(string s1, string s2) {   //滑动窗口 双指针+哈希表
        unordered_map<char, int> mp1;     //保存字符串1中每个字符出现的个数
        unordered_map<char, int> mp2;     //保存字符串2中每个字符出现的个数
        int s1_len = s1.size();
        int s2_len = s2.size();
        if(s1_len> s2_len) return false;  //字符串1应小于字符串2
        int left = 0, right = left + s1_len - 1;
        for (auto &&i : s1){               //初始化mp1
            mp1[i]++;
        }
        
        for(int i = left;i <= right;i++){  //初始化mp2
            mp2[s2[i]]++;
        }
        while(right < s2_len){
            if(mp1 == mp2) return true;     // 匹配成功，返回条件
            if(--mp2[s2[left]] == 0) mp2.erase(s2[left]);  //窗口向右滑动，判断是否有字符为0，删除为0的字符串
            left++;
            right++;
            mp2[s2[right]]++;
        }
        return false;
    }
};
// @lc code=end


/**
 * 题目：
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
 * 如果是，返回 true ；否则，返回 false 。
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 * 示例 1：
 *      输入：s1 = "ab" s2 = "eidbaooo"
 *      输出：true
 *      解释：s2 包含 s1 的排列之一 ("ba").
*/