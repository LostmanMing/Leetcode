/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
#include<map>
using namespace std;
class MyCalendar {
public:
    MyCalendar() {
        mp[-1] = -1;
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(end);
        if((--it)->second > start) return false;
        mp[start] = end;
        return true;
    }
    map<int,int> mp;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

