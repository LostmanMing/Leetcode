/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
#include<queue>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {// 定义深度优先搜索函数，输入为当前节点指针
        auto res = dfs(root);// 当节点为空，递归终止
        return res;// 返回空指针
    }
    TreeNode* dfs(TreeNode* node){
        if(!node){
            return nullptr;
        }
        node->left =  dfs(node->left);// 递归调用dfs函数，对左子树进行剪枝
        node->right = dfs(node->right);// 递归调用dfs函数，对右子树进行剪枝
        if(!node->left && !node->right && node->val == 0){
            node = nullptr;
        }
        return node;
    }
};
// @lc code=end

//题目
/**
 * 给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
 * 返回移除了所有不包含 1 的子树的原二叉树。
 * 节点 node 的子树为 node 本身加上所有 node 的后代。
 * 输入：root = [1,null,0,0,1]
 * 输出：[1,null,0,null,1]
 * 只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
 * 
*/