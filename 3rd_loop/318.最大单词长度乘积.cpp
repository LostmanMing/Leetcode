/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        vector<int> mask(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < words[i].size();j++){
                mask[i] |= 1 << (words[i][j] - 'a');
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if((mask[i] & mask[j]) == 0){                 // 有括号
                    int num = words[i].size()*words[j].size();
                    res = max(res,num);
                }
            }
        }
        return res;
    }
};
// @lc code=end

