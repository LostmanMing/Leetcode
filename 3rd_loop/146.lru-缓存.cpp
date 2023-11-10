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
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto p = *mp[key];
        cache.erase(mp[key]);
        cache.push_front(p);
        mp[key] = cache.begin();
        return p.second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            cache.erase(mp[key]);
            mp.erase(key);
        }else{
            if(cache.size() == capacity){
                mp.erase(cache.back().first);
                cache.pop_back();
            }
        }
        cache.push_front({key,value});
        mp[key] = cache.begin();
    }

    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> mp;

    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

