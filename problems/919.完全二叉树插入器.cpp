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
        // 使用广度优先搜索，遍历完全二叉树并找到所有待插入节点的父节点
        while(!q.empty()){
            TreeNode* node = q.front();// 取出队首节点
            q.pop();                   // 弹出队首节点
            if(node->left){            // 如果当前节点有左子节点，将左子节点入队
                q.push(node->left);
            }
            if(node->right){           // 如果当前节点有右子节点，将右子节点入队
                q.push(node->right);
            }
            if(!(node->left && node->right)){ // 如果当前节点不是满节点，则将其添加到待插入节点队列中
                candidate.push(node);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* child = new TreeNode(val);  // 创建新节点
        TreeNode* parent = candidate.front(); // 取出待插入节点的父节点
        if(!parent->left){              // 如果父节点没有左子节点，将新节点插入左子节点
            parent->left = child;
        }else if(!parent->right){       // 否则，将新节点插入右子节点，并将父节点从待插入队列中弹出
            parent->right = child; 
            candidate.pop();
        }
        candidate.push(child);          // 将新节点加入待插入队列
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    queue<TreeNode*> candidate;      // 待插入节点队列
    TreeNode* root;               // 根节点
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

//题目
/**
 * 完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
 * 
 * 设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。
 * 实现 CBTInserter 类:
 * CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
 * CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点 TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
 * CBTInserter.get_root() 将返回树的头节点。
 * 
 * 示例 1：
 * 输入
 * ["CBTInserter", "insert", "insert", "get_root"]
 * [[[1, 2]], [3], [4], []]
 * 输出
 * [null, 1, 2, [1, 2, 3, 4]]
 * 
 * 
 * 
*/