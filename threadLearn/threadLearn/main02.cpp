#include <iostream>
#include <thread>
#include <future>
#include <string>

int main02() {
        //创建封装了lambda函数的packaged_task<>
        std::packaged_task<std::string(std::string)> task([](std::string token) {
            std::string data = "Data From " + token;
            for (int i = 0;i<50;++i)
            {
                std::cout << "thread...out num:" << i<<std::endl;
            }
        
         return data;

    });

        
    //从packaged_task<>获取相关的future<>
            std::future<std::string> result = task.get_future();

            
    //将packaged_task传递给线程以异步运行
                std::thread th(std::move(task), "Arg");


    //join线程，阻塞直到线程完成时返回
                    th.detach();
                    for (int j = 0;j<20;++j)
                    {
                        std::cout << "main ...out num :"<<j << std::endl;

                    }
    //获取packaged_task<>的结果，即getDataFromDB()的返回值

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
