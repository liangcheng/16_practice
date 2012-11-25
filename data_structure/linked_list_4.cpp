#include <iostream>

using namespace std;

struct Node;
class Linkedlist;
int main();

struct Node
{
    Node *next;
    double data;
};

class Linkedlist
{
private:
Node *p_current;
Node *p_start;

public:
Linkedlist();
~Linkedlist();
bool Append_to_tail(double val);
bool Delete();
bool Insert_in_front(double val);
void Display();
};

Linkedlist::Linkedlist()
{
    Node *node = new Node;
    node->data = 0;
    node->next = NULL;
};


Linkedlist::~Linkedlist()
{
    Node *it = p_start;

    while(it)
    {
        Node *tmp = it->next;
        delete it;
        it = tmp;
        cout<<"Delete one node in the list.\n";
    }
};


bool Linkedlist::Append_to_tail(double data)
{
    Node *node = new Node;

    if(!node) {cerr<<"No new node generated in Append_to_tail()!\n";}

    node->data = data;
    p_current->next = node;
    p_current = node;

    return true;
}

bool Linkedlist::Insert_in_front(double data)
{
    Node *node = new Node;
    if(!node) {cerr<<"No new node generated in Insert_in_front()!\n"}
    node->data = data;
    node->next = p_start;
    p_start = node;

    return true;
}

bool Linkedlist::Delete (Node *delete_me)
{
    Node *it = p_start;

    while(it)
    {
        if(it->next == delete_me)
        {
            it->next = delete_me->next;
            delete delete_me;
            return true;
        }
        it = it->next;
    }
    return false;
}


int main()
{

    return 0;
}

