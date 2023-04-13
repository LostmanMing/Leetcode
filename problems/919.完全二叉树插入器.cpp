// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem919.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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

class CBTInserter {
public:
    CBTInserter(TreeNode* root):root(root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(!(node->left && node->right)){
                candidate.push(node);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* child = new TreeNode(val);
        TreeNode* parent = candidate.front();
        if(!parent->left){
            parent->left = child;
        }else if(!parent->right){
            parent->right = child;
            candidate.pop();
        }
        candidate.push(child);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    queue<TreeNode*> candidate;
    TreeNode* root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

