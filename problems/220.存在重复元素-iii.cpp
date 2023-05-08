// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem220.h"

using namespace std;
// @before-stub-for-debug-end

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
    LL size; // 定义一个 long long 类型的成员变量 size
    bool containsNearbyAlmostDuplicate(vector <int> & nums, int k, int t) {
        int n = nums.size();
        unordered_map<LL, LL> m; // 定义一个无序的键值对 map，键和值都是 long long 类型
        size = t + 1L; // 计算桶的大小，将 t 转化为 long long 类型
        for (int i = 0; i < n; i++) {
            LL u = nums[i] * 1L; // 将当前元素转化为 long long 类型
            LL idx = getIdx(u); // 获取当前元素所在的桶的下标
            // 目标桶已存在（桶不为空），说明前面已有 [u - t, u + t] 范围的数字
            if (m.find(idx) != m.end()) return true; // 如果目标桶已经存在，直接返回 true
            // 检查相邻的桶
            LL l = idx - 1, r = idx + 1; // 获取相邻的桶的下标
            if (m.find(l) != m.end() && abs(u - m[l]) <= t) return true; // 如果左边的桶存在，并且与当前元素的差的绝对值小于等于 t，返回 true
            if (m.find(r) != m.end() && abs(u - m[r]) <= t) return true; // 如果右边的桶存在，并且与当前元素的差的绝对值小于等于 t，返回 true
            // 建立目标桶
            m.insert({idx, u}); // 在 map 中插入当前元素
            // 移除下标范围不在 [max(0, i - k), i) 内的桶
            if (i >= k) m.erase(getIdx(nums[i - k])); // 如果桶的下标超出了范围 [max(0, i - k), i)，将其从 map 中删除
        }
        return false; // 没有找到符合条件的元素，返回 false
    }
    LL getIdx(LL u) { // 获取元素所在的桶的下标
        return u >= 0 ? u / size : ((u + 1) / size) - 1;
    }
};
// @lc code=end

