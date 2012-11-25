// it is a C-style doubly linked list data structure

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int _data;
    Node *_next;
    Node *_prev;
};

Node *start_ptr = NULL;
Node *current;		 // Used to move along the list


bool Add_node_at_end(Node *head, int data)
{
    Node *node = new Node;

    node->_data = data;
    while(head !=NULL)
    {
        head = head->_next;
    }
    head = node;

    cout<<"insert "<<node->_data <<" to the list.\n";
    return true;
}




bool deleteElement(Node **head, Node *deleteMe)
{
    Node *elem = *head;

    if (deleteMe == *head)
    {
        *head = elem->_next;
        delete deleteMe;

        cout<<"delete "<< deleteMe->_data <<" from the list.\n";
        return true;

    }

    while (elem)
    {
        if (elem->_next == deleteMe)
        {
            elem->_next == deleteMe->_next;
            delete deleteMe;

            cout<<"delete "<<deleteMe->_data <<" from the list.\n";
            return true;
        }
        elem = elem->_next;
    }

    return false;
}

void deleteList (Node **head)
{
    Node *deleteMe = *head;
    while (deleteMe)
    {
        Node *next = deleteMe->_next;
        delete deleteMe;
        deleteMe = next;
    }

    *head = NULL;
    cout<<"delete the entire list.\n";
}


void PrintList ()
{
    Node *temp = start_ptr;

    if (temp == NULL)
        cout << "The list is empty!" << endl;
    else
    {
        while (temp)
        {
            cout << temp->_data<< " -> ";
            temp = temp->_next;
        }
        cout << "End of list!\n";
    }


}

int main ()
{
    Node *node = new Node;
    start_ptr = node;

    Add_node_at_end(node, 1);
//    Add_node_at_end(node, 2);


//    PrintList();

    return 0;
}
