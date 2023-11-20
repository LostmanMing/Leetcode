/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return res;
    }

    void dfs(TreeNode* root, long long sum){
        if(!root){
            return ;
        }

        sum -= root->val;
        if(sum == 0){
            res++;
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
    }

    int res = 0;
};
// @lc code=end

