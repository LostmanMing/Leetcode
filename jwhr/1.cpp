#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;
// 题目1 翻转链表
// 题目2 10进制 1-n整数中所有 1的个数
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int NumberOf1Between1AndN_Solution(int n) {
        vector<int> res(n+1,0);
        for(int i = 1;i <= n;i++){
            res[i] = res[i/10] + ((i % 10) == 1 ? 1 : 0);
        }
        return accumulate(res.begin(),res.end(),0);
    }
};

int main(){
    Solution s;
    std::cout << s.NumberOf1Between1AndN_Solution(5) << std::endl;
    return 0;
}