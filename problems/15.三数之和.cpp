/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        if(size < 3) return ans;      //不够三个数，直接返回空
        sort(nums.begin(), nums.end()); //排序
        for(int i = 0; i < size-2; i++){  //三个数，所以要 -2
            if (nums[i] > 0) break;
            if(i > 0 && (nums[i] == nums[i-1])) continue; //当前数和上一个数相同，直接跳过，避免重复
            int left = i + 1, right = size -1;   //i指向第一个值，左指针指向第二个值
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) left++;
                else if (sum > 0) right--;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && (nums[left]==nums[left+1])) left++;     //同样避免重复
                    while(left < right && (nums[right]==nums[right-1])) right--;  //同样避免重复
                    left++;     //当前三个值已经能够返回结果，第一个值固定，那么只移动一个值必然要移动第二个值，除非重复，上一步避免重复
                    right--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

