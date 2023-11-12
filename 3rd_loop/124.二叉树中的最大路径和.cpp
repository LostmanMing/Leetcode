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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int &sum){
        if(!root){
            return 0;
        }

        int max_l = max(0, dfs(root->left,sum));
        int max_r = max(0, dfs(root->right,sum));

        int lmr = root->val + max_l + max_r;

        sum = max(sum, lmr);

        return root->val + max(max_l,max_r);
    }
};
// @lc code=end

