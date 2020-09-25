#include <iostream>
#include <thread>


void threadFun(const int& num)//线程的参数必须为常引用
{
    int& numref = const_cast<int&>(num);
    std::cout << "in thread num地址:" << &num << std::endl;
    std::cout << "in thread numref地址:" << &numref << std::endl;
    numref = 20;
}

int main_www()
{
    int a = 10;
    std::cout << "main a地址:" << &a << std::endl;
    //原因是，考虑了函数式编程(如std::bind)在使用时，是对参数直接拷贝，而不是引用。具体可以参照这一句话：
    //std::reference_wrapper 用于按引用传递对象给 std::bind 或 std::thread 的构造函数

    std::thread threadObj(threadFun, std::ref(a));


    threadObj.join();
    std::cout << "main after thread a地址" << &a << std::endl;
    std::cout << "main after thread a = " << a << std::endl;
    return 0;
}