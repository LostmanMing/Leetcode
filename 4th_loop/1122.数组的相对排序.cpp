/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto& i : arr1){
            mp[i]++;
        }
        vector<int> res;
        for(auto& i: arr2){
            while(mp[i]-- > 0){
                res.push_back(i);
            }
            mp.erase(i);
        }
        for(auto& m : mp){
            while(m.second--){
                res.push_back(m.first);
            }
        }
        return res;
    }
};
// @lc code=end

