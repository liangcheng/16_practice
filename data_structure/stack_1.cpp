#include <iostream>

using namespace std;
typedef double NewType;

struct Node;
class Stack;
int main();

struct Node
{
    Node *_next;
    NewType _data;
};

class Stack
{
private:
    Node *head;
public:
    Stack();
    ~Stack();
    bool Push(NewType data);
    double Pop();
    void Display();
};


Stack::Stack()
{
    Node *node = new Node;
    node->_data = 0;
    node->_next = NULL;
    head = NULL;
};

bool Stack::Push(NewType data)
{
    Node *node = new Node;
    node->_data = data;
    node->_next = head;
    head = node;

    cout<<"Push a node to the stack.\n";
    return true;
};


void Stack::Display()
{
    Node *tmp = head;
    cout<<"-=top=-\n";
    while(tmp)
    {
    cout<< tmp->_data<<"\n";
    tmp = tmp->_next;
    }
    cout<< "-=bottom=-\n";
};

double Stack::Pop()
{
    if(!head){cerr<<"stack is already empty!\n";}

    Node *tmp=head->_next;
    double tmp2=head->_data;

    delete head;
    head = tmp;

    cout<<"Pop out a node from stack.\n";
    return tmp2;
};



Stack::~Stack()
{
    while(head)
    {
        Node *tmp = head->_next;
        delete head;
        head = tmp;
        cout<<"Delete one node in the stack.\n";
    }

};

int main()
{
    Stack *pS = new Stack;
    pS->Push(0.2);
    pS->Push(1.1);
    pS->Push(3.2);
    pS->Push(0.6);

    pS->Display();
    delete pS;
    return 0;
};














