
#include <iostream>

#include <thread>

//传给线程的地址和指针参数要小心，因为主线程中（指针可能会析构变量失效后地址变的不可控）；

void newThreadCallback(int* p) {

    std::cout << "Inside Thread : p = " << *p << std::endl;

    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);

    std::cout << "Inside Thread after sleep: p = " << *p << std::endl;
    *p = 20;
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

int main_be_care_thread_paremeter() {

    startNewThread();
    //std::cout << std::this_thread::get_id() << std::endl;
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);
    return 0;
}
