#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;
//using /define
using myInt = int;

class Persion
{
public:
    //Persion() = default;
    Persion(int age) :m_age{10} {

    }
    Persion(int a, int b) = delete;
    void getAge() {
        cout << "age:" << m_age << endl;
    }

private:
    int m_age{30};//类内初始化
};

void messageError(initializer_list<string> ls)
{
    for (auto it = ls.begin();it!=ls.end();++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
//     const int a = 10;
//     decltype(a) b = 20;//类型指示
//     cout <<"a"<<a << endl;
//     cout << "b" << b << endl;

    messageError({ "hello","glodon","nihao","shanghai" });
    Persion aa;

    return 0;
}