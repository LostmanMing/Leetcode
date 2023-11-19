/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
#include<vector>
#include<random>
#include<unordered_map>
using namespace std;
class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1; 
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int pos = mp[val];
        arr[pos] = arr.back();
        mp[arr.back()] = pos;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
    vector<int> arr;
    unordered_map<int,int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

