//template design pattern by Liang 6/19/2013
//a parent class can neforce an invariant for its subclasses
#include <iostream>

class View
{
public:
    void Display()
    {
        SetFocus(); //concrete method
        DoDisplay(); //hook operation
        ResetFocus(); //concrete method
    }

private:
    virtual void DoDisplay() = 0;
    void SetFocus()
    {
        std::cout<<"View::SetFocus(). \n";
    }
    void ResetFocus()
    {
        std::cout<<"View::ResetFocus(). \n \n";
    }
};

class myView : public View
{
public:
    /*virtual*/void DoDisplay()
    {
        std::cout<<"myView::DoDisplay(). \n";
    }
};

class myView2 : public View
{
public:
    /*virtual*/void DoDisplay()
    {
        std::cout<<"myView2::DoDisplay(). \n";
    }
};




using namespace std;
int main()
{
    View *p1 = new myView;
    View *p2 = new myView2;

    p1->Display();
    p2->Display();

    delete p1;
    delete p2;

    myView mv;
    mv.Display();

    myView2 mv2;
    mv2.Display();

    return 0;
}
