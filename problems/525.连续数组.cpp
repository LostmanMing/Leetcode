/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;              //记录前缀和第一次出现的下标
        mp[0] = -1;                             //
        int n = nums.size();
        int sum = 0, res = 0;
        for(int i = 0;i < n;i++){
            sum += (nums[i]==0 ? -1:1);
            if(mp.count(sum)){                  //如果当前前缀和sum已经在哈希表中出现过了
                res = max(res, i - mp[sum]);    //更新最长子数组长度
            }else{
                mp[sum] = i;    
            }
        }
        return res;
    }
};
// @lc code=end

