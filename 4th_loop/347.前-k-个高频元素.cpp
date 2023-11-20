/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto & num : nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto & m : mp){
            q.push({m.second,m.first});
            if(q.size() > k){
                q.pop();
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
// @lc code=end

