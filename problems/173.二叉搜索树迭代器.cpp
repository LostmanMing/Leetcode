/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
#include <stack>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        dfs(root);// 在构造函数中调用 dfs() 函数进行中序遍历
    }
    void dfs(TreeNode* root){
        while(root){
            d.push(root);// 将当前结点压入栈中
            root = root->left;// 将当前结点指向其左子结点
        }

    }   
    int next() {
        TreeNode* root = d.top();// 取出栈顶元素
        d.pop();// 弹出栈顶元素
        int res = root->val;// 获取当前结点的值
        root = root->right;/ 将当前结点指向其右子结点
        dfs(root);// 将右子树结点及其左子结点都入栈
        return res;
    }
    
    bool hasNext() {
        return !d.empty();// 判断栈是否为空
    }
    stack<TreeNode*> d;// 定义一个栈用于存储结点
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

