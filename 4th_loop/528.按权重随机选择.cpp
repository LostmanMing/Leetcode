/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<random>
using namespace std;
class Solution {
public:
    Solution(vector<int>& w) {
        partial_sum(w.begin(),w.end(),back_inserter(sum));
    }
    
    int pickIndex() {
        int idx = rand() % sum.back();
        
        return upper_bound(sum.begin(),sum.end(),idx) - sum.begin();
    }
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

