/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_set>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int     x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right) return false;
        dfs(root);
        for(auto &m : mp){
            if(find(mp.begin(),mp.end(),k - m)!=mp.end() && (k -m) != m){
                return true;
            }
        }
        return false;
    }
    void dfs(TreeNode* root){
        if(!root) return ;
        dfs(root->left);
        mp.insert(root->val);
        dfs(root->right);
    }
    unordered_set<int> mp;
};
// @lc code=end

//题目
/**
 * 给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 示例 1：
 * 输入: root = [5,3,6,2,4,null,7], k = 9
 * 输出: true
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/