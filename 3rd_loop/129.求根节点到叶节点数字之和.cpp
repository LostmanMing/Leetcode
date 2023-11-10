/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
#include<functional>
using namespace std;
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* head,int num){
            if(!head) return ;
            num = num*10+head->val;
            if(!head->left && !head->right) sum+=num;
            dfs(head->left,num);
            dfs(head->right,num);
        };
        dfs(root,0);
        return sum;
    }
};
// @lc code=end

