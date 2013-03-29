/**
* test the singleton design pattern
* ����ģʽ�����þ��Ǳ�֤������Ӧ�ó�������������У��κ�һ��ʱ�̣�
* �������ʵ����ֻ����һ��;
*
* static object, non-implemented copy constructor and assign operation,
* private ctor, static instance().
*
* @author liang cheng
* @date 11/28/2012
**/

#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton *_single;

protected:
    Singleton(){};
    // Dont forget to declare these two. You want to make sure they
    // are unaccessable otherwise you may accidently get copies of
    // your singleton appearing.
    Singleton(Singleton const &s){}; // Don't Implement
    const Singleton &operator=(Singleton const &s)
    {
        if (this !=&s)
        {
            return *this;
        }
    }; // Don't implement



public:
    static Singleton* Instance();
    void Show_star();
};


Singleton *Singleton::_single =NULL;

Singleton *Singleton::Instance()
{
    if(!_single)
    {
        _single = new Singleton;
        cout << " create new. \n";
    }
    else
        cout << " use the existing one. \n";
    return _single;
};

void Singleton::Show_star()
{
    cout<<"\n";
    cout<< "************************************";
        cout<<"\n";
};

int main()
{
    Singleton *p1 = Singleton::Instance();
    Singleton *p2 = Singleton::Instance();

    if (p1 == p2)
        cout << " s1 and s2 share the same address! \n";

    return 0;
}
