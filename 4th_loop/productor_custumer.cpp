#include<thread>
#include<iostream>
#include<condition_variable>
#include<mutex>
#include<queue>


std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;

int main(){
    std::thread productor([&]{
        for(int i = 0;i < 20;i++){
            std::unique_lock<std::mutex> UniqueLock(mtx);
            while(q.size() >= 10){
                cv.wait(UniqueLock);
            }
            q.push(i);
            std::cout<<"productor: " << i << std::endl;
            cv.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
    
    std::thread customer([&]{
        for(int i = 0;i < 20;i++){
            std::unique_lock<std::mutex> UniqueLock(mtx);
            while(q.empty()){
                cv.wait(UniqueLock);
            }
            int val = q.front();
            q.pop();
            std::cout<<"customer: " << val << std::endl;
            cv.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    productor.join();
    customer.join();
    return 0;
}