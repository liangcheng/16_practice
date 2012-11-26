/**
 * find the mth to last node in a singly linked list
 **/

#include <iostream>
#include <list>

using namespace std;

struct Node;
Node* Get_last_mth(Node* head, int m);
int main();

Node* Get_last_mth(Node* head, int m)
{
    if (m<1) return NULL;

    Node* p1 = head;
    Node* p2 = head;
    for(int i=0; i<m, ++i)
    {
        p1= p1->_next;
    }

    while(p1)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main()
{

}
