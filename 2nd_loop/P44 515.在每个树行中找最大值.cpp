// 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

// 示例1：



// 输入: root = [1,3,2,5,3,null,9]
// 输出: [1,3,9]
// 示例2：

// 输入: root = [1,2,3]
// 输出: [1,3]
 

// 提示：

// 二叉树的节点个数的范围是 [0,104]
// -231 <= Node.val <= 231 - 1


/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty()){
            int maxsize = q.size();
            int maxVal = INT_MIN;
            while(maxsize > 0){
                auto front = q.front();
                q.pop();
                maxsize--;
                maxVal = max(maxVal, front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            res.push_back(maxVal);
        }
        return res; 
    }
};
// @lc code=end

