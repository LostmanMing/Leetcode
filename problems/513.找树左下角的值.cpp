/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
//    TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int qsize = q.size();
            TreeNode* node =  q.front();
            q.pop();
            if(node->right){
                    q.push(node->right);
            }
            if(node->left){
                    q.push(node->left);
            }
            res = node->val;
        }
        return res;
    }
};
// @lc code=end
//题目
/**
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 假设二叉树中至少有一个节点。
 * 
 * 示例 1:
 * 输入: root = [2,1,3]
 * 输出: 1
 * 
 * 
*/
