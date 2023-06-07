/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 创建一个最小堆（小顶堆）priority_queue
        // 存储整数类型，并按升序排列
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto &n : nums){
            // 如果堆的大小已经达到了 k，并且当前元素 n 小于等于堆顶元素，则跳过当前元素
            // 这样可以确保堆中始终保持 k 个最大的元素
            if(q.size() == k && q.top() >= n) continue;   
            // 如果堆的大小已经达到了 k，则弹出堆顶元素  
            if( q.size() == k){
                q.pop();
            }
            q.push(n);
        }
        return q.top();
    }
};
// @lc code=end

