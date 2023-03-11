// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {       //前缀和
public:  
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum  == total - (sum + nums[i])){
                return i;
            }
            sum += nums[i];

        }
        return -1;
    }
};
// @lc code=end


    //傻瓜版
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         unordered_map<int ,int> mp;
//         for(int i = 0; i < n; i++){
//             sum += nums[i];
//             mp[i] = sum;
//         }
//         for(int i = 0; i < n;i++){
//             if((mp[i] - nums[i]) == (mp[n-1] - mp[i])){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };