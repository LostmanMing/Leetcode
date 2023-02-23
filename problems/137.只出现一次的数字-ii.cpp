/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (auto &i : nums)
        {
            umap[i]++;
        }
        int ans = 0;
        for ( auto & i : umap)
        {
            if(i.second == 1) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

