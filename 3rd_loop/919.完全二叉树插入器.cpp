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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
            if(!p->left || !p->right){
                c.push(p);
            }
            
        }
    }
    
    int insert(int val) {
 
        auto front = c.front();
        auto node = new TreeNode(val);
        if(front->left){
            front->right = node;
            c.pop();
        }else{
            front->left = node;
        }
        c.push(node);
        return front->val;
        
    }
    
    TreeNode* get_root() {
        return root;
    }
    TreeNode* root;
    queue<TreeNode*> c;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

