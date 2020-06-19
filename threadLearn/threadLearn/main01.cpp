
#include <iostream>

#include <thread>



void newThreadCallback(int* p) {

    std::cout << "Inside Thread :  "" : p = " << *p << std::endl;

    std::chrono::milliseconds dura(1000);

    std::this_thread::sleep_for(dura);

    //*p = 20;
    std::cout << "Thread is over" << std::endl;
    //std::cout << "P:"<<*p << std::endl;
}



void startNewThread() {

    int i = 1;

    std::cout << "Main Thread :  "" : i = " << i << std::endl;

    std::thread t(newThreadCallback, &i);

    t.detach();

    std::cout << "Main Thread :  "" : i = " << i << std::endl;

}



int main01() {

    startNewThread();

    std::chrono::milliseconds dura(2000);

    std::this_thread::sleep_for(dura);

    return 0;

}
