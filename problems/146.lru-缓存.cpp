/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        auto k_v = *map[key];     //从哈希表中获取key对应的catch节点指针
        cache.erase(map[key]);    //从链表中删除key对应的节点
        cache.push_front(k_v);    //将key-value节点插入链表头部
        map[key] = cache.begin(); //在哈希表中更新key对应的迭代器位置
        return k_v.second;
    }
    
    void put(int key, int value) {
        if(map.find(key) == map.end()){
            if(map.size() == cap){      //如果链表已满，需要删除最久未使用的节点
                map.erase(cache.back().first); //从哈希表中删除最久未使用的节点
                cache.pop_back();  //从链表尾部删除最久未使用的节点
            }
        }else{
            cache.erase(map[key]);   //如果key已存在，需要将节点从链表中删除
        }
        cache.push_front({key,value}); //将新节点插入链表头部
        map[key] = cache.begin();    //在哈希表中更新key对应的迭代器位置
    }
private:
    int cap;  //缓存容量
    list<pair<int, int>> cache;  //链表容器，存储key-value节点
    unordered_map<int, list<pair<int,int>>::iterator> map;  //哈希表容器，存储key对应的迭代器位置
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


//题目
/**
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 * 实现 LRUCache 类：
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
 * 如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 * 
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 
 * 示例：
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，
 * 缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，
 * 缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
*/
