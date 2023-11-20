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
    TreeNode* increasingBST(TreeNode* root) {
        queue<int> q;
        dfs(root,q);
        TreeNode* dummy = new TreeNode();
        auto head = dummy;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            auto node = new TreeNode(front);
            head->right = node;
            head = head->right;
        }
        return dummy->right;
    }

    void dfs(TreeNode* root,queue<int>& q){
        if(!root){
            return ;
        }

        dfs(root->left,q);
        q.push(root->val);
        dfs(root->right,q);
    }
};
// @lc code=end

