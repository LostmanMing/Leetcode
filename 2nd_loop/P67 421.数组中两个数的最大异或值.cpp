// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

 

// 示例 1：

// 输入：nums = [3,10,5,25,2,8]
// 输出：28
// 解释：最大运算结果是 5 XOR 25 = 28.
// 示例 2：

// 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// 输出：127
 

// 提示：

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 231 - 1



/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
#include<vector>
using namespace std;
struct Trie{
    Trie(): next(2,nullptr){}

    void insert(int num){
        auto node = this;
        for(int i = 30;i >= 0 ;i--){
            int n = num >> i & 1;
            if(!node->next[n]){
                node->next[n] = new Trie();
            }
            node = node->next[n];
        }
    }

    int search(int num){
        auto node = this;
        int res = 0;
        for(int i = 30;i >= 0 ;i--){
            int n = num >> i & 1;
            if(node->next[!n]){
                res = res*2 + 1;
                node = node->next[!n];
            }else{
                res = res*2 + 0;
                node = node->next[n];
            }

        }
        return res;
    }

    vector<Trie*> next;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Trie();
        int res = 0;
        for(auto & num : nums){
            root->insert(num);
        }
        for(auto & num : nums){
            res = max(res,root->search(num));
        }
        return res;
    }
    Trie* root;
};
// @lc code=end

