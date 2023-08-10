// 给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。

 

// 示例 1：


// 输入: root = [5,3,6,2,4,null,7], k = 9
// 输出: true
// 示例 2：


// 输入: root = [5,3,6,2,4,null,7], k = 28
// 输出: false
 

// 提示:

// 二叉树的节点个数的范围是  [1, 104].
// -104 <= Node.val <= 104
// 题目数据保证，输入的 root 是一棵 有效 的二叉搜索树
// -105 <= k <= 105




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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        for(auto & s : set){
            if(set.count(k - s) && (k -s) != s){
                return true;
            }
        }
        return false;
    }
private:
    void dfs(TreeNode* root){
        if(!root){
            return ;
        }
        dfs(root->left);
        set.insert(root->val);
        dfs(root->right);
    }
    unordered_set<int> set;
};
// @lc code=end

