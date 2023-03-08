/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {               //前缀和  + 哈希表   求nums数组中某个子数组的和，可以通过计算它的前缀和之差得到。
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = 1;                       // 当结果子数组的起始位置为0时，需要有一个前缀和为0的位置
        int n = nums.size();
        int sum = 0,res = 0;
        for(int i = 0;i < n;i++){    
            sum += nums[i];    //计算当前位置前缀和
            if(mp.count(sum - k)){          // 存在前缀和为sum - k的位置，那我一定存在一个子数组为 k ==> sum -(sum - k) = k
                res += mp[sum - k];
            }
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end

/**首先，这个算法使用了前缀和的思想。
具体地，对于nums数组中的任意一个位置i，它的前缀和sum[i]表示从nums[0]到nums[i]这个子数组的和。
因此，如果我们想求nums数组中某个子数组的和，可以通过计算它的前缀和之差得到。

例如，对于nums数组中的任意一个位置i和j（i<j），
我们可以通过计算sum[j]-sum[i-1]得到从nums[i]到nums[j]这个子数组的和。
在这个算法中，我们要求的是nums数组中和为k的子数组的个数。为了实现这个目标，
我们可以遍历nums数组，计算每个位置的前缀和，并使用一个哈希表mp来记录每个前缀和出现的次数。

具体地，对于nums数组中的任意一个位置i，
我们可以计算出前i个元素的和sum[i]，并判断sum[i]-k是否在mp中。如果在mp中，说明存在一个位置j（j<i），
使得从nums[j+1]到nums[i]这个子数组的和等于k。此时，我们可以将这个子数组的个数加入到结果中。

但是，这个算法中有一个特殊的情况，就是从nums[0]开始的子数组的和等于k。
在这种情况下，前缀和sum[0]等于k，因此如果我们不特殊处理这种情况，就会漏掉这些子数组。
为了避免这种情况，我们需要在mp中初始化一个值为1的项，表示有1个子数组的和等于0（即从nums[0]到nums[0]的子数组）。

因此，我们需要将mp[0]设置为1，这样当遍历到i=0时，sum[0]=nums[0]，mp[sum[0]-k]就等于mp[k-nums[0]]，
这个值可能是0，但是因为我们初始化了mp[0]=1，所以最终的结果是正确的。*/




