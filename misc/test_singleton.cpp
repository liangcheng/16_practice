/**
 *  write a singleton pattern for fun.
 * @author Liang
 * @date 11/19/2012
 */
#include <iostream>

class Singleton
{
private:
    static bool _instanceFlag;
    static Singleton *_single;
    Singleton()
    {

    }

public:
    static Singleton *getInstance();
    void method();
    ~Singleton()
    {
        _instanceFlag = false;
    }
};

bool Singleton::_instanceFlag = false;

Singleton* Singleton::_single = NULL;

Singleton* Singleton::getInstance()
{
    if(!_instanceFlag)
    {
        _single = new Singleton();
        _instanceFlag = true;
        return _single;
    }
    else
    {
        return _single;
    }
}

void Singleton::method()
{
    std::cout <<"Method of the singleton parttern. \n" ;
}

int main()
{
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    std::cout<< sc1 <<" , " << sc2 <<"\n";

    delete sc1, sc2;
    return 0;
}
