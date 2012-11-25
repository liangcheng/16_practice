// linked list written in C++

#include <iostream>

using namespace std;

struct Node;
class Linkedlist;
int main();

struct Node
{
    double _data;
    Node *_next;
};

class Linkedlist
{
private:
    Node *p_current;
    Node *p_start;

public:
    Linkedlist();
    ~Linkedlist();
    double Get(int i);
    bool Set(double val);
    void Display();
};

Linkedlist::Linkedlist()
{
    p_start = new Node;
    p_start->_data = 0;
    p_start->_next = NULL;
    p_current = NULL;
};

bool Linkedlist::Set(double val)
{
    if(!p_current)
    {
        p_start->_data =val;
        p_current = p_start;
    }
    else
    {
        Node *node = new Node;
        node->_data = val;
        node->_next = NULL;
        p_current->_next = node;
        p_current = node;
    }
    cout <<"Add a node to linked list.\n";
    return true;
};

double Linkedlist::Get(int i)
{
    Node *tmp = p_start;
    for (unsigned int j=1; j<i; ++j)
    {
        tmp = tmp->_next;
    }
    if(!tmp)
    {
        cout<<"Number i node does not exist!\n";
        return -1;
    }
    return tmp->_data;
};

void Linkedlist::Display()
{
    Node *it = p_start;
    while(it)
    {
        cout<< it->_data <<" -> ";
        it = it->_next;
    }
    cout<<"End of list! \n";
};



Linkedlist::~Linkedlist()
{
    Node *it = p_start;
    Node *tmp = it;
    while(it)
    {
        tmp = it;
        delete it;
        it = tmp->_next;
        cout<<"Delete one node in the list.\n";
    }

};




int main()
{
    Linkedlist *pLL = new Linkedlist;
    pLL->Set(0.1);
    pLL->Set(0.4);
    pLL->Set(0.8);
    pLL->Set(1.2);
    pLL->Display();

    delete pLL;
}








