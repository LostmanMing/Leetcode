/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto& s : s1){
            mp1[s]++;
        }
        for(int i = 0;i < n1;i++){
            mp2[s2[i]]++;
        }
        int l = 0,r = n1 - 1;
        while(r < n2){
            if(mp1 == mp2){
                return true;
            }
            if(--mp2[s2[l]] == 0) mp2.erase(s2[l]);
            r++;
            l++;
            mp2[s2[r]]++;
        }
        return false;
    }
};
// @lc code=end

