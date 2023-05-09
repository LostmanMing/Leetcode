/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
#include <map>
using namespace std;
class MyCalendar {
public:
    MyCalendar() {
    //避免越界
        mp[-1] = -1;
    }
    
    bool book(int start, int end) {
        //找到大于等于end的第一个start,如果没找到，返回end()
        auto it = mp.lower_bound(end);
        //看前一个区间内是否包含start
        if((--it)->second > start){
            return false;
        }
        //不重叠，放入map
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

//题目

/**
 * 
 * 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 重复预订 ，则可以存储这个新的日程安排。
 * 
 * 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 重复预订 。
 * 
 * 日程可以用一对整数 start 和 end 表示，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end 。
 * 
 * 实现 MyCalendar 类：
 * MyCalendar() 初始化日历对象。
 * boolean book(int start, int end) 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true 。否则，返回 false 并且不要将该日程安排添加到日历中。
 * 
 * 
 * 示例：
 * 输入：
 * ["MyCalendar", "book", "book", "book"]
 * [[], [10, 20], [15, 25], [20, 30]]
 * 
 * 输出：
 * [null, true, false, true]
 * 
*/