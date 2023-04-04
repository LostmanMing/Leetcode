/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;
class RandomizedSet {

unordered_map <int ,int> hash;
vector<int> arr;

public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(hash.find(val) != hash.end()) return false;//如果集合中已经存在val，返回false，节省时间
        arr.push_back(val);
        hash[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(hash.find(val) == hash.end()) return false; //删除时，如果集合中不存在val，返回false
        int lastpos = arr.size() - 1; //将被删除值和数组最后一位进行交换
        int curpos = hash[val];

        arr[curpos] = arr[lastpos];  
        hash[arr[curpos]] = curpos;  //被交换的值下标发生变化，需要更新
        
        arr.pop_back();  //vector数组删除val
        hash.erase(val);  //哈希表中删除val的项

        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

//题目
/**
 * 实现RandomizedSet 类：
 * 
 * RandomizedSet() 初始化 RandomizedSet 对象
 * bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
 * bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
 * int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
 * 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
 * 
 * 示例：
 * 输入
 * ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
 * [[], [1], [2], [2], [], [1], [2], []]
 * 输出
 * [null, true, false, true, 2, true, false, 2]
 * 
*/