/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //保存两数之和以及两个数
        priority_queue<pair<int, vector<int>>> q;
        for(const int& a : nums1)
        {
            for(const int& b : nums2)
            {
                //队列大小最大为k
                if(q.size() < k)
                    q.push({a+b, {a, b}});
                //比队列中最小的还小则进队
                else if(a+b < q.top().first){
                    q.pop();
                    q.push({a+b, {a, b}});
                }
                //因为有序，所以后续肯定比上一个还大，必然不满足条件，直接跳出循环。
                else break;
            }
        }
        vector<vector<int>> ans;
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

//题目
/**
 * 
 * 
 * 给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
 * 
 * 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
 * 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
 * 
 * 示例 1:
 * 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * 输出: [1,2],[1,4],[1,6]
 * 解释: 返回序列中的前 3 对数：
 *  [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 
 * 
 * 
 * 
*/