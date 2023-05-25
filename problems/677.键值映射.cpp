// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem677.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;
struct Trie{
    bool is_End;
    int val;
    Trie* next[26];
    Trie(){
        is_End = false;
        val = 0;
        for(auto &n : next){
            n = nullptr;
        }
    }
};
class MapSum {
public:
    MapSum() {
        root = new Trie();
    }
    void insert(string key, int val) {
        Insert(root, key,val);
    }
    int sum(string prefix) {
        int res = 0;
        Trie*cur = root;
        //先判断前缀存不存在
        for(auto&c:prefix){
            if(!cur->next[c - 'a']){
                return 0;
            }
            cur = cur->next[c - 'a'];
        }
        //遍历对前缀后的字符
        res += dfs(cur);
        return res;
    }
private:
    void Insert(Trie* root, const string &word, int val){
        for(auto &c : word){
            if(!root->next[c - 'a']){
                root->next[c - 'a'] = new Trie();
            }
            root = root->next[c - 'a'];
        }
        root->is_End = true;
        root->val = val;
    }
    //遍历获得root节点后所有val的和
    int dfs(Trie*root){
        if(!root) return 0;
        int res = root->val;
        for(int i = 0; i < 26;i++){
            if(root->next[i]){
                res += dfs(root->next[i]);
            } 
        }
        return res;
    }
public:
    Trie *root;

};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

//题目
/**
 * 
 * 设计一个 map ，满足以下几点:
 *      字符串表示键，整数表示值
 *      返回具有前缀等于给定字符串的键的值的总和
 * 
 * 实现一个 MapSum 类：
 * MapSum() 初始化 MapSum 对象
 * void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键
 * key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对。
 * int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 * 
 * 示例 1：
 * 输入：
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * 输出：
 * [null, null, 3, null, 5]
 * 解释：
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);  
 * mapSum.sum("ap");           // 返回 3 (apple = 3)
 * mapSum.insert("app", 2);  
 * mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
 * 
 * 
 * 
 * 
 * 
 * 
*/