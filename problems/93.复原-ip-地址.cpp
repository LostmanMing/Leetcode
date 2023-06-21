// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return res;
        dfs(s,0,0);
        return res;
    }
    void dfs(string &s, int startIdx, int pointNum){
        if(pointNum == 3){
            if(is_vailid(s, startIdx, s.size() - 1)){
                res.push_back(s);
            }
            return;
        }
        for(int i = startIdx;i < s.size();i++){
            if(is_vailid(s,startIdx,i)){
                s.insert(s.begin() + i + 1,'.');
                pointNum++;
                dfs(s, i + 2,pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }else break;
        }
    }
    bool is_vailid(string s, int start, int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i = start;i <= end;i++){
            if(s[i] > '9' && s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
    vector<string> res;

};
// @lc code=end


//题目
/**
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
 * 
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * 
 * 示例 1：
 * 输入：s = "25525511135"
 * 
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 
 * 
 * 
*/
