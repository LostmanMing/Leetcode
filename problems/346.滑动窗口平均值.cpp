#include <iostream>
#include <queue>
using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) :_size(size){
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        windows.push(val);
        if(windows.size() > _size){
            sum -= windows.front();
            windows.pop();
        }
        return 1.0 * sum / windows.size();
    }
private:
    int _size;
    int sum;
    queue<int> windows;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */