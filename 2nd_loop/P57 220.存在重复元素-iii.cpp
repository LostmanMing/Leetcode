// 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

// 如果存在则返回 true，不存在返回 false。

 

// 示例 1：

// 输入：nums = [1,2,3,1], k = 3, t = 0
// 输出：true
// 示例 2：

// 输入：nums = [1,0,1,1], k = 1, t = 2
// 输出：true
// 示例 3：

// 输入：nums = [1,5,9,1,5,9], k = 2, t = 3
// 输出：false
 

// 提示：

// 0 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 104
// 0 <= t <= 231 - 1

/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#define LL long long
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<LL,LL> mp;   // idx nums[i]
        int n = nums.size();
        size = valueDiff + 1;  //加1是因为 <= valueDiff，可以让等于的情况也进来
        for(int i = 0;i < n;i++){
            LL val = nums[i] * 1L;
            int idx = getID(val);
            //删除失效的桶（超过 indexDiff 大小）
            if(i > indexDiff){
                mp.erase(getID(nums[i - indexDiff - 1])); 
            }
            //存在桶
            if(mp.count(idx)) return true;
            //不存在桶，判断相邻的桶是否满足条件
            int l = idx - 1, r = idx + 1;
            if((mp.count(l) && abs(mp[l] - val) <= valueDiff) || 
                (mp.count(r) && abs(mp[r] - val) <= valueDiff)) return true;
            //插入桶
            mp.insert({idx,val});
        }
        return false;
    }
private:
    LL size;
    int getID(LL n){
        //-1是为了避免0附近的负数分到正数桶中和0一起。u+1是为了负数的=valueDiff的边界也能在同一个桶中
        return n >= 0 ? (n / size) : (n + 1) / size - 1;
    }
};
// @lc code=end

