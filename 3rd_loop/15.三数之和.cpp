/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0;i < n;i++){
            if(nums[i] > 0 && nums[i] == nums[i+1]) continue;
            int l = i + 1,r = n - 1;
            while(l < r){
                int num = nums[i] + nums[l] + nums[r];
                if(num < 0){
                    l++;
                }else if(num > 0){
                    r--;
                }else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;r--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

