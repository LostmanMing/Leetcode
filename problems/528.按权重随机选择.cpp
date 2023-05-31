/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<numeric>
#include<random>
using namespace std;
class Solution {
public:
    std::vector<int> presum;
    Solution(vector<int>& w) { 
        partial_sum(w.begin(),w.end(),back_inserter(presum));  //stl中求前缀和的函数
    }
    
    int pickIndex() {
        int num = rand() % presum.back();
        return upper_bound(presum.begin(),presum.end(),num) - presum.begin();   //upper_bound返回大于num的第一个元素的迭代器，减去开始元素的迭代器就是索引值。
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

//题目
/**
 * 给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。
 * 请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）选出并返回
 * 一个下标。选取下标 i 的 概率 为 w[i] / sum(w) 。
 * 
 * 例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），
 * 而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。
 * 
 * 示例 1：
 * 输入：
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * 输出：
 * [null,0]
 * 解释：
 * Solution solution = new Solution([1]);
 * solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。
 * 
 * 
 * 
*/