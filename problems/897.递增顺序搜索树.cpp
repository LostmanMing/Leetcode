/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
#include<vector>
using namespace std;
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* dummpy = new TreeNode(-1);
        TreeNode* ans = dummpy;
        for(auto & v:val){
            ans->right = new TreeNode(v);   //重新建一个树
            ans = ans->right;
        }
        return dummpy->right;
    }
    void dfs(TreeNode* root){
        if(!root) return ;
        dfs(root->left);
        val.push_back(root->val);     //按中序记录每个节点的值
        dfs(root->right);
    }
private:
    vector<int> val;
};
// @lc code=end

//题目
/**
 * 给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点.
 * 示例 1：
 * 输入：root = 
 * [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 输出：
 * 
 * [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * 
*/