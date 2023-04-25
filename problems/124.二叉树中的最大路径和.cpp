/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#include<algorithm>
#include<climits>
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
    int maxPathSum(TreeNode* root) {
        int num = INT_MIN;
        dfs(root, num);
        return num;
    }
    int dfs(TreeNode* root, int &val){
        //终止条件
        if(!root)  return 0;
        //深度优先，获取左右分支的最大路径和，本结点作为联络点
        //若左右分支返回的值为负数，则对路径和做负贡献，直接舍弃
        int left_max = max(0, dfs(root->left, val));
        int right_max = max(0, dfs(root->right, val));
        //由于路径最大的一种可能为left->node->right，而不向root的父结点延伸
        int lmr = root->val + left_max + right_max;
        //更新最大值，全是负数结点的情况，也会在这里更新最大的负数
        val = max(val, lmr);
        //向node的父结点返回经过node的单边分支的最大路径和
        return root->val + max(left_max, right_max);
    }

};
// @lc code=end

//题目
/**
 * 
 * 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。
 * 该路径 至少包含一个 节点，且不一定经过根节点。
 * 
 * 路径和 是路径中各节点值的总和。
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 * 
 * 示例 1：
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 * 
 * 
*/