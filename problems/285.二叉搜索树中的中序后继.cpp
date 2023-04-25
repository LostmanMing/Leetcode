/*
 * @lc app=leetcode.cn id=285 lang=cpp
 *
 * [285] 二叉搜索树中的中序后继
 */

// @lc code=start

#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {   //将等于p的node的下一个输出，没有返回null
        TreeNode* res = nullptr;
        for(int i = 0;i < tv.size() - 1; i++){
            if(tv[i]->val == p->val){
                res = tv[i+1];
                break;
            }
        }
        return res;
    }
    void dfs(TreeNode* root){         //dfs将二叉搜索树按中序放入vector中。
        if(!root) return;
        dfs(root->left);
        tv.push_back(root);
        dfs(root->right);
    }
    vector<TreeNode*> tv;
};
// @lc code=end


//题目
/**
 * 给定一棵二叉搜索树和其中的一个节点 p ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 null 。
 * 节点 p 的后继是值比 p.val 大的节点中键值最小的节点，即按中序遍历的顺序节点 p 的下一个节点。
 * 示例 1：
 * 输入：root = [2,1,3], p = 1
 * 输出：2
 * 解释：这里 1 的中序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。
 * 
 * 
 * 
 * 
 * 
*/
