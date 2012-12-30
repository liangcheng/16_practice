/**
* test the singleton design pattern
* 单例模式的作用就是保证在整个应用程序的生命周期中，任何一个时刻，
* 单例类的实例都只存在一个;
* static object, non-implemented copy constructor and assign operation,
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
    Singleton::Instance()->Show_star();

    if (Singleton::Instance() == Singleton::Instance())
        cout << " s1 and s2 share the same address! \n";

    return 0;
}
