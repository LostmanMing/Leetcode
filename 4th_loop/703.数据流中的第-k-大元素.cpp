/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto & num : nums){
            q.push(num);
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size() > K){
            q.pop();
        }
        return q.top();
    }
    int K;
    priority_queue<int,vector<int>,greater<int>> q;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

