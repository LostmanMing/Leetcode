/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;

#define LL long long
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<LL,LL> mp;
        int n = nums.size();
        size = valueDiff + 1;
        for(int i = 0;i < n;i++){
            LL val = nums[i] * 1L;
            int idx = getID(val);
            if(i > indexDiff){
                mp.erase(getID(nums[i-indexDiff-1]));
            }
            if(mp.count(idx)) return true;
            int l = idx - 1, r = idx + 1;
             if((mp.count(l) && abs(mp[l] - val) <= valueDiff) || 
                (mp.count(r) && abs(mp[r] - val) <= valueDiff)) return true;

            mp.insert({idx,val});
        }
        return false;
    }
private:
    LL size;
    int getID(LL n){
        return n >= 0 ? (n / size) : (n + 1) / size - 1;
    }
};
// @lc code=end

