/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<string>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_map,t_map;  // 记录t中各字符出现次数的哈希表
        int left = 0, right = 0;               // 左右指针
        int valid = 0;            // 记录s_map中满足t_map条件的字符个数
        int start = 0, len = INT_MAX;   // 最短子串的起始位置和长度
        for (auto &&i : t){
            t_map[i]++;
        }
        
        while(right < s.size()){
            if(t_map.count(s[right])){     //如果窗口右边界为t中的字符
                s_map[s[right]]++;         
                if(s_map[s[right]] == t_map[s[right]]){   //满足t中字符个数要求
                    valid ++;             //满足t_map条件的字符个数 + 1
                }
            }
            right++;   //右移窗口

            while(valid == t_map.size()){    //当满足条件时，右移窗口左边界
                if(right - left < len){      //记录当前 窗口起始位位置和长度
                    start = left;
                    len = right - left;
                }
                if(t_map.count(s[left])){    //如果左边界为t中的字符，将左边界减1，进一步如果还是在刚好满足个数的时候，需要将满足的个数减1
                    if(t_map[s[left]] == s_map[s[left]]){
                        valid --;
                    }
                    s_map[s[left]]--;
                }
                left++;                //右移窗口
            }
        }
        if(len == INT_MAX) return "";
        else return s.substr(start, len);
    }
};
// @lc code=end

