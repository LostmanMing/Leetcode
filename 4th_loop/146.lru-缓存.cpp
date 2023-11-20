/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include<list>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto node = *mp[key];
        cache.erase(mp[key]);
        cache.push_front(node);
        mp[key] = cache.begin();
        return node.second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto node = *mp[key];
            cache.erase(mp[key]);
            mp.erase(key);
        }else{
            if(n == mp.size()){
                mp.erase(cache.back().first);
                cache.pop_back();
            }
        }
        cache.push_front({key,value});
        mp[key] = cache.begin();
    }
    int n;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

