// 设计一个 map ，满足以下几点:

// 字符串表示键，整数表示值
// 返回具有前缀等于给定字符串的键的值的总和
// 实现一个 MapSum 类：

// MapSum() 初始化 MapSum 对象
// void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对。
// int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 

// 示例 1：

// 输入：
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// 输出：
// [null, null, 3, null, 5]

// 解释：
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);  
// mapSum.sum("ap");           // 返回 3 (apple = 3)
// mapSum.insert("app", 2);    
// mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
 

// 提示：

// 1 <= key.length, prefix.length <= 50
// key 和 prefix 仅由小写英文字母组成
// 1 <= val <= 1000
// 最多调用 50 次 insert 和 sum


/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Trie {
public:
    Trie():isEnd(false), val(0),next(26,nullptr) {}

    bool isEnd;
    int val;
    vector<Trie*> next;
};

class MapSum {
public:
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        auto node = root;
        for(auto& c : key){
            if(!node->next[c-'a']){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
        node->val = val;
    }
    
    int sum(string prefix) {
        auto node = root;
        for(auto & c: prefix){
            if(!node->next[c-'a']) return 0;
            node = node->next[c-'a'];
        }
         
        return dfs(node);
    }

    int dfs(Trie* head){
        if(!head) return 0;
        int res = head->val;

        for(int i = 0;i < 26;i++){
            if(head->next[i]){
                res += dfs(head->next[i]);
            }
        }
        return res;
    }
    Trie* root;
};

// int main(){
//     MapSum mp;
//     mp.insert("apple",3);
//     cout << mp.sum("ap")<<'\n';
//     mp.insert("app",2);
//     cout << mp.sum("ap")<<'\n';
//     return 0;
// }
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

