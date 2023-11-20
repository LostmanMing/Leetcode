/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        multimap<int,vector<int>> mp;
        for(int i = 0;i < n1;i++){
            for(int j = 0;j < n2;j++){
                mp.insert({nums1[i] + nums2[j],{nums1[i],nums2[j]}});
            }
        }
        vector<vector<int>> res;
        for(auto & m : mp){
            if(k > 0){
                res.push_back(m.second);
            }else break;
            k--;
        }

        return res;
    }


};
// @lc code=end

