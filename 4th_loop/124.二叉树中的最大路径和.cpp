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
#include<climits>
#include<vector>
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
        int res = INT_MIN;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root,int& sum){
        if(!root){
            return 0;
        }

        int lmax = max(0,dfs(root->left,sum));
        int rmax = max(0,dfs(root->right,sum));

        int lmr = lmax + root->val + rmax;

        sum = max(sum, lmr);

        return root->val + max(lmax,rmax);
    }
};
// @lc code=end

