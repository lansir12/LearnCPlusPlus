#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>

using namespace std;

class MyString
{
public:
    static size_t CCtor; //ͳ�Ƶ��ÿ������캯���Ĵ���
    static size_t MCtor; //ͳ�Ƶ����ƶ����캯���Ĵ���
    static size_t CAsgn; //ͳ�Ƶ��ÿ�����ֵ�����Ĵ���
    static size_t MAsgn; //ͳ�Ƶ����ƶ���ֵ�����Ĵ���

public:
    // ���캯��
    MyString(const char* cstr = 0) {
        if (cstr) {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        }
        else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    // �������캯��
    MyString(const MyString& str) {
        CCtor++;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }
    // �ƶ����캯��
    MyString(MyString&& str) noexcept
        :m_data(str.m_data) {
        MCtor++;
        str.m_data = nullptr; //����ָ��֮ǰ����Դ��
    }

    // ������ֵ���� =������
    MyString& operator=(const MyString& str) {
        CAsgn++;
        if (this == &str) // �������Ҹ�ֵ!!
            return *this;

        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

    // �ƶ���ֵ���� =������
    MyString& operator=(MyString&& str) noexcept {
        MAsgn++;
        if (this == &str) // �������Ҹ�ֵ!!
            return *this;

        delete[] m_data;
        m_data = str.m_data;
        str.m_data = nullptr; //����ָ��֮ǰ����Դ��
        return *this;
    }

    ~MyString() {
        delete[] m_data;
    }

    char* get_c_str() const { return m_data; }
private:
    char* m_data;
};

size_t MyString::CCtor = 0;
size_t MyString::MCtor = 0;
size_t MyString::CAsgn = 0;
size_t MyString::MAsgn = 0;

int main02()
{
    clock_t copy_startTime = clock();
    vector<MyString> vecStr;
   // vecStr.reserve(100000); //�ȷ����1000���ռ�
    for (int i = 0; i < 100000; i++) {
        MyString tmp("hello");
        vecStr.push_back(tmp); //���õ��ǿ������캯��
    }
    clock_t copy_endTime = clock();
    cout << "copyTime :" << copy_endTime - copy_startTime << endl;
    cout << "CCtor = " << MyString::CCtor << endl;
    cout << "MCtor = " << MyString::MCtor << endl;
    cout << "CAsgn = " << MyString::CAsgn << endl;
    cout << "MAsgn = " << MyString::MAsgn << endl;

    cout << endl;
    MyString::CCtor = 0;
    MyString::MCtor = 0;
    MyString::CAsgn = 0;
    MyString::MAsgn = 0;
    clock_t move_startTime = clock();
    vector<MyString> vecStr2;
    //vecStr2.reserve(100000); //�ȷ����1000���ռ�
    for (int i = 0; i < 100000; i++) {
        MyString tmp("hello");
        vecStr2.push_back(std::move(tmp)); //���õ����ƶ����캯��
    }
    clock_t move_endTime = clock();
    cout << "moveTime :" << move_endTime - move_startTime << endl;
    cout << "CCtor = " << MyString::CCtor << endl;
    cout << "MCtor = " << MyString::MCtor << endl;
    cout << "CAsgn = " << MyString::CAsgn << endl;
    cout << "MAsgn = " << MyString::MAsgn << endl;

    return 0;
}


class Copyable {
public:
    Copyable() {}
    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }

    Copyable(Copyable&&o) {
        cout << "Moved" << endl;
    }
};

vector<Copyable> vec;
vector<Copyable> vec2;
void AcceptVal(Copyable a) {
    vec.emplace_back(a);
}

void AcceptRef(const Copyable& a) {
    vec2.push_back(a);
}

int main03() {
    Copyable copyObject;
    cout << "pass by value: " << endl;
    AcceptVal(Copyable()); // Ӧ�õ������ο������캯��
    Copyable copyObject2;
    cout << "pass by reference: " << endl;
    AcceptRef(copyObject2); //Ӧ��ֻ����һ�ο������캯��
    return 0;
}


class testDemo
{
public:
    testDemo(int num) :num(num) {
        std::cout << "���ù��캯��" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "���ÿ������캯��" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "�����ƶ����캯��" << endl;
    }
private:
    int num;
};

int main04()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    testDemo aa(2);
    demo1.emplace_back(aa);

    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    testDemo bb(2);
    demo2.push_back(bb);

    cout << "*******************" << endl;
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo3;
    demo3.emplace_back(2);

    cout << "push_back:" << endl;
    std::vector<testDemo> demo4;
    demo4.push_back(2);
    return 0;
}

class Tree 
{
public:
    //Ĭ�Ϲ��캯��
    Tree() {}
    Tree(int high) :m_high(high) {
        cout << "construct" << endl;
    }
    Tree(const Tree& obj) {
        this->m_high = obj.m_high;
        cout << "copy construct" << endl;
    }
    Tree(Tree&& obj) {
        this->m_high = obj.m_high;
        cout << "move construct" << endl;
    }

    Tree &operator = (const Tree& obj) {

        this->m_high = obj.m_high;
        cout << "copy assign construct" << endl;
        return *this;
    }

    Tree& operator = (Tree&& obj) noexcept{
        if (&obj == this)
            return *this;
        this->m_high = obj.m_high;
        cout << "move assign construct" << endl;
        return *this;
    }

private:
    int m_high;

};

int main05() {

    Tree tree1(10);
    Tree tree2 = tree1;

    Tree tree3 = std::move(tree1);

    return 0;
}