// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem752.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000")) return -1;
        if(target == "0000") return 0;
        queue<string> q;
        unordered_map<string, int> mp;
        mp.insert({"0000",0});
        visited.insert("0000");
        q.push("0000");
        while(!q.empty()){
            string front = q.front();
            q.pop();
            int path = mp[front];
            for(int i = 0;i < 4;i++){
                for(int j = -1;j < 2;j+=2){
                    string newnum = front;
                    char a = (newnum[i] - '0' + j + 10) % 10 + '0';
                    newnum[i] = a;
                    if(newnum == target) return path + 1;
                    if(visited.find(newnum) == visited.end()){
                        visited.insert(newnum);
                        mp.insert({newnum,path+1});
                        q.push(newnum);
                    }
                }
            }

        }
        return -1;
    }
};
// @lc code=end

//题目

/**
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
 * 
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
 * 
 * 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
 * 字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。
 * 示例 1:
 * 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * 
 * 输出：6
 * 解释：
 * 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
 * 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
 * 因为当拨动到 "0102" 时这个锁就会被锁定。
 * 
 * 
*/