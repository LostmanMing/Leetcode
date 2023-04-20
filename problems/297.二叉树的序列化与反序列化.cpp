/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<string>
#include<algorithm>
#include<list>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(root);// dfs序列化二叉树
        return str;// 返回序列化结果
    }
    // 递归函数，将以root为根的二叉树序列化到str字符串中
    void dfs(TreeNode* root){
        if(root == nullptr){
            str += "null,";  // 如果当前节点为空，将"null,"添加到序列化结果中
        }else{
            str += to_string(root->val) + ","; // 如果当前节点不为空，将当前节点的值加入序列化结果中
            dfs(root->left);// 递归序列化左子树
            dfs(root->right); // 递归序列化右子树
        }
    }
    // 递归函数，根据字符串slist还原出一个二叉树
    TreeNode* rev_dfs(list<string>& slist){
        if(slist.front() == "null"){  // 如果当前字符串的第一个元素是"null"，说明当前节点为空
            slist.erase(slist.begin());// 删除字符串的第一个元素
            return nullptr;// 返回空指针  说明这一边的树已经没有孩子节点，应该换另一边
        }
        // 否则，当前节点不为空，构造当前节点并递归构造左右子树
        TreeNode* root = new TreeNode(stoi(slist.front()));
        slist.erase(slist.begin());
        root->left = rev_dfs(slist);
        root->right = rev_dfs(slist);

        return root;  // 返回构造好的二叉树根节点
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string dstr;
        list<string> slist;
        for(auto& d:data){
            if(d == ','){
                slist.push_back(dstr);
                dstr.clear();
            }else{
                dstr.push_back(d);
            }
        }
        if(!dstr.empty()){
            slist.push_back(dstr);
            dstr.clear();
        }
        return rev_dfs(slist);
    }
    string str;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

//root = [1,2,3,null,null,4,5]