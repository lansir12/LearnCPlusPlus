#include <iostream>
#include <thread>


void threadFun(const int& num)//�̵߳Ĳ�������Ϊ������
{
    int& numref = const_cast<int&>(num);
    std::cout << "in thread num��ַ:" << &num << std::endl;
    std::cout << "in thread numref��ַ:" << &numref << std::endl;
    numref = 20;
}

int main_www()
{
    int a = 10;
    std::cout << "main a��ַ:" << &a << std::endl;
    //ԭ���ǣ������˺���ʽ���(��std::bind)��ʹ��ʱ���ǶԲ���ֱ�ӿ��������������á�������Բ�����һ�仰��
    //std::reference_wrapper ���ڰ����ô��ݶ���� std::bind �� std::thread �Ĺ��캯��

    std::thread threadObj(threadFun, std::ref(a));


    threadObj.join();
    std::cout << "main after thread a��ַ" << &a << std::endl;
    std::cout << "main after thread a = " << a << std::endl;
    return 0;
}