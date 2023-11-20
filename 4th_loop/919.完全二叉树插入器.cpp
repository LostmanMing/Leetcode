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
        queue<TreeNode*> queue;
        this->head = root;
        queue.push(root);
        while(!queue.empty()){
            auto front = queue.front();
            queue.pop();
            if(front->left){
                queue.push(front->left);
            }
            if(front->right){
                queue.push(front->right);
            }
            if(!front->left || !front->right){
                q.push(front);
            }
        }
    }
    
    int insert(int val) {
        auto front = q.front();
        auto node = new TreeNode(val);
        if(!front->left){
            front->left = node;
        }else if(!front->right){
            front->right = node;
            q.pop();
        }
        q.push(node);
        return front->val;
    }
    
    TreeNode* get_root() {
        return head;
    }
    TreeNode* head;
    queue<TreeNode*> q;

};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

