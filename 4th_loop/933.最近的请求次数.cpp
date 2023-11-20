/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
#include<queue>
using namespace std;
class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        while(!q.empty() && q.front() < t - 3000){
            q.pop();
        }
        q.push(t);
        return q.size();
    }

    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

