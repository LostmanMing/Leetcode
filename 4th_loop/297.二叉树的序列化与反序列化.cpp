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
#include<list>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> l;
        string str;
        for(auto & s : data){
            if(s == ','){
                l.push_back(str);
                str.clear();
            }else{
                str.push_back(s);
            }
        }

        if(!str.empty()){
            l.push_back(str);
            str.clear();
        }
        return rev_dfs(l);
    }

    void dfs(TreeNode* root, string & str){
        if(!root){
            str += "null,";
            return ;
        }

        str += to_string(root->val) + ',';
        dfs(root->left,str);
        dfs(root->right,str);
    }

    TreeNode* rev_dfs(list<string>& l){
        if(l.front() == "null"){
            l.pop_front();
            return nullptr;
        }

        auto root = new TreeNode(stoi(l.front()));
        l.pop_front();
        root->left = rev_dfs(l);
        root->right  = rev_dfs(l);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

