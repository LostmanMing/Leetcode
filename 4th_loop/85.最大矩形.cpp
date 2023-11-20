/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<int> height(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            res = max(res,submaximalRectangle(height));
        }
        return res;
    }

    int submaximalRectangle(vector<int>& height){
        stack<int> s;
        height.push_back(0);
        int n = height.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            while(!s.empty() && height[i] < height[s.top()]){
                int h = height[s.top()];
                s.pop();
                if(s.empty()){
                    res = max(res, h * i);
                }else{
                    res = max(res, h * (i - s.top() - 1));
                }
            }
            s.push(i);
        }
        return res;
    }

};
// @lc code=end

