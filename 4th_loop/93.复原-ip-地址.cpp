/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include<vector>
#include<string>
#include<functional>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        function<void(int,int)> dfs = [&](int start,int pointNum){
            if(pointNum == 3){
                if(isValid(s,start,s.size()-1)){
                    res.push_back(s);
                }
                return ;
            }
            for(int i = start;i < s.size();i++){
                if(isValid(s,start,i)){
                    s.insert(s.begin() + i + 1,'.');
                    pointNum++;
                    dfs(i+2,pointNum);
                    pointNum--;
                    s.erase(s.begin() + i + 1);
                }else break;
            }
        };
        dfs(0,0);
        return res;
    }
    bool isValid(string s, int start,int end){
        int sum = 0;
        if(start > end) return false;
        if(start != end && s[start] == '0') return false;
        for(int i = start;i <= end;i++){
            sum = sum * 10 +(s[i] - '0');
            if(sum > 255) return false;
        }
        return true;
    }
private:
    vector<string> res;
};
// @lc code=end

