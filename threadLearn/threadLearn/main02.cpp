#include <iostream>
#include <thread>
#include <future>
#include <string>

int main02() {
        //������װ��lambda������packaged_task<>
        std::packaged_task<std::string(std::string)> task([](std::string token) {
            std::string data = "Data From " + token;
            for (int i = 0;i<50;++i)
            {
                std::cout << "thread...out num:" << i<<std::endl;
            }
        
         return data;

    });

        
    //��packaged_task<>��ȡ��ص�future<>
            std::future<std::string> result = task.get_future();

            
    //��packaged_task���ݸ��߳����첽����
                std::thread th(std::move(task), "Arg");


    //join�̣߳�����ֱ���߳����ʱ����
                    th.detach();
                    for (int j = 0;j<20;++j)
                    {
                        std::cout << "main ...out num :"<<j << std::endl;

                    }
    //��ȡpackaged_task<>�Ľ������getDataFromDB()�ķ���ֵ

    std::string data;
    //data = result.get();
        std::cout << data << std::endl;
        for (int k= 0;k<20;k++)
        {
            std::cout << "bottom main out num :" << k << std::endl;
        }
        system("pause");
     return 0;
 }
