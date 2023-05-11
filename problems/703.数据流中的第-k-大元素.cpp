/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        mst.insert(nums.begin(),nums.end());

    }
    
    int add(int val) {
        mst.insert(val);
        while(mst.size() > K) {
            mst.erase(mst.begin());
        }
        return *mst.begin();
    }
    multiset<int> mst;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

