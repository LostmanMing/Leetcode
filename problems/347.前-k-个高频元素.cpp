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
        unordered_map<int, int> mp;
        for(auto &n:nums){
            mp[n]++;
        }
        //优先队列可以自定义数据优先级，让优先级高的排在前面，对基础类型默认大顶堆。
        priority_queue<pair<int,int>> pq;
        for(auto& m:mp){
            pq.emplace(m.second,m.first);
        }
        vector<int> res;
        while(k){
            res.emplace_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
// @lc code=end

//题目
/**
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 
 * 输出: [1,2]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/