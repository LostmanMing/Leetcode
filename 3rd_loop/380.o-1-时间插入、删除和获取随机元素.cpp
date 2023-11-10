/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<random>
using namespace std;
class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        vec.push_back(val);
        mp[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int lastpos = vec.size()-1;
        int curpos = mp[val];
        
        vec[curpos] = vec[lastpos];
        mp[vec[curpos]] = curpos;

        mp.erase(val);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec[(rand() % vec.size())];
    }
    unordered_map<int,int> mp;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

