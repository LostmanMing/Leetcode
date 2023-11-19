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
        if(n2 < n1) return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i = 0;i < n1;i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        int l = 0, r = n1 - 1;
        while(r < n2){
            if(mp1 == mp2) return true;
            if(--mp2[s2[l]] == 0){
                mp2.erase(s2[l]);
            }
            l++;
            r++;
            mp2[s2[r]]++;
        }
        
        return false;
    }
};
// @lc code=end

