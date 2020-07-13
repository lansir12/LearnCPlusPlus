#include <iostream>
#include <time.h>
#include <string>
#include <memory>

using namespace std;

class  Persion
{
public:
    Persion(string name): m_name(name) {}
    ~Persion() {
        cout << "Îö¹¹º¯Êý" <<m_name<< endl;
    }
    void GetName() {
        cout << "name:" << m_name << endl;
    }
    void GetEge() {
        srand(time(0));
        cout << rand() << endl;
    }
private:
    string m_name;
};



int main01()
{
    shared_ptr<Persion> p_xiaoHong(new Persion("xiaohong"));
    p_xiaoHong->GetName();
    p_xiaoHong->GetEge();

    cout << "---------------" << endl;

    unique_ptr<Persion> p_xiaoGang(new Persion("xiaogang"));
    p_xiaoGang->GetName();
    p_xiaoGang->GetEge();

    unique_ptr<Persion> p_xiangGangGang = move(p_xiaoGang);
    p_xiangGangGang->GetName();
    p_xiangGangGang->GetEge();
    
    Persion* p = p_xiangGangGang.get();
    p->GetName();
    p_xiangGangGang->GetName();

    Persion* pp = p_xiangGangGang.release();
    pp->GetName();
    p_xiangGangGang->GetName();
    cout << "---------------" << endl;
    return 0;
}