/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
#include <vector>
using namespace std;
struct Trie{
    Trie*next[2];
    Trie(){
        for(auto &n : next){
            n = nullptr;
        }
    }
    void insert(int num){
        auto node = this;
        for(int i = 30; i >= 0;i--){
            int n = num >> i & 1;
            if(!node->next[n]){
                node->next[n] = new Trie();
            }
            node = node->next[n];
        }
    }
    //由于异或在值取反的，所以优先找有没有相反的节点。
    int search(int num){
        auto node = this;
        int res = 0;
        for(int i = 30; i >= 0;i--){
            int n = num >> i & 1;     //31位是符号位，30 - 0分别右移并&上1得到
            if(node->next[!n]){
                res  = res*2 + !n;
                node = node->next[!n];
            }else{
                res = res*2 + n;
                node = node->next[n];
            }
        }
        //得到的res是尽可能和原数按位相反最多的值，此时与原数异或，能够得到异或最大值。
        res ^= num;
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        Trie * root = new Trie();
        for(auto & num : nums){
            root->insert(num);
        }
        for(auto &num : nums){
            res = std::max(root->search(num), res) ;
        }
        return res;
    }
};
// @lc code=end

//题目

/**
 * 
 * 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
 * 
 * 
 * 示例 1：
 * 输入：nums = [3,10,5,25,2,8]
 * 输出：28
 * 解释：最大运算结果是 5 XOR 25 = 28.
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
 * 
 * 
 */
