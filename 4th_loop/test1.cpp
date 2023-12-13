//测试释放指针空间，还能使用指针所指向的函数吗
#include<iostream>
class A{
    public:
    void hellow(){
        std::cout << "hello world" << std::endl;
    }
    
};

int main(){
    A* p = new A();

    delete p;
    p->hellow();
    return 0;
}