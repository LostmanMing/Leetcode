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
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        dfs(root, targetSum);   //以root为起始点查找路径
        pathSum(root->left,targetSum);  //左子树递归
        pathSum(root->right,targetSum);  //右子树递归
        return res;
    }
    void dfs(TreeNode* root, long long sum){
        if(!root){
            return;
        }
        sum -= root->val;
        if(sum == 0){  //注意不要return,因为不要求到叶节点结束,所以一条路径下面还可能有另一条
            res++; //如果找到了一个路径全局变量就+1
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
private:
    long long res = 0;
};
// @lc code=end

