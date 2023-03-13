/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int s_size = s.size();
        int p_size = p.size();
        if(p_size > s_size) return res;
        for (auto &&i : p){                    //初始化哈希表
            mp1[i]++;
        }
        int left = 0, right = left + p_size - 1;
        for(int i = 0;i <= right;i++){
            mp2[s[i]]++;
        }
        while(right < s_size){                       //固定长度滑动窗口
            if(mp1 == mp2) res.push_back(left);      
            if(--mp2[s[left]] == 0) mp2.erase(s[left]);  //**从哈希表中删除值为0的字符
            left++;
            right++;
            mp2[s[right]]++;
        }
        return res;
    }
};
// @lc code=end

