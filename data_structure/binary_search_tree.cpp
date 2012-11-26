//BST: Binary serach tree
#include <iostream>

using namespace std;

struct Node;
class BinarySearchTree;


struct Node
{
    Node *left;
    Node *right;
    int data;
};

class BinarySerachTree
{
private:
    Node *_root;

public:
    BinarySerachTree()
    {
        _root =NULL;
    }

    ~BinarySerachTree()
    {
        Free_node(_root);
    }

    void Store(int a);
    bool Remove(int d);
    void In_order (Node *node);
    void Pre_order (Node *node);
    void Post_order (Node *node);
    void Display();
};



void BinarySerachTree::Store(int a)
{
    Node *node = new Node;
    node->data = a;
    node->left = NULL;
    node->right = NULL;

    Node *parent = NULL;
    Node *curr = NULL;

    if (_root == NULL) _root = node;
    else
    {
        curr = _root;
        while(curr)
        {
            parent = curr;
            if(node->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if(node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;
    }
}; // two loop pointer, one is parent, one is current,
//serach down to the left and find a positoin.


bool BinarySerachTree::Remove(int d)
{
    bool found;


    if(!_root) return false;
    else
    {
        Node *curr;
        Node *parent;
        curr = _root;

        while(curr)
        {
            if(curr->data ==d)
                found = true;
            else
            {
                parent = curr;
                if (curr->data < d) curr = curr->right;
                else curr = curr->left;
            }
        }
    }

    if(!found)
        cout<<"data is not found.\n";


}


void BinarySerachTree::Free_node(Node *leaf)
{
    if(leaf)
    {
        if(leaf->left) Free_node(leaf->left);
        if (leaf->right) Free_node(leaf->right);
        delete leaf;
    }
}


void BinarySerachTree::In_order(Node *p)
{
    if(p)
    {
        if(p->left)
            In_order(p->left);
        cout<< " " <<p->data << " ";
        if(p->right)
            In_order(p->right);
    }
    else
        return;
}

void BinarySerachTree::Pre_order(Node *p)
{
    if(p)
    {
        cout<< " "<<p->data <<" ";
        if(p->left) Pre_order(p->left);
        if (p->right) Pre_order(p->right);
    }
    else return;
}

void BinarySerachTree::Post_order(Node *p)
{
    if(p)
    {
        if(p->left) Post_order(p->left);
        if (p->right) Post_order(p->right);
        cout<< " "<<p->data <<" ";
    }
    else return;
}



void BinarySerachTree::Display()
{
    In_order(_root);
    cout<<"\n";
    Pre_order(_root);
    cout<<"\n";
    Post_order(_root);
}

int main(int argc, char* argv[])
{
    BinarySerachTree *bst = new BinarySerachTree;

    bst->Store(4);
    bst->Store(100);
    bst->Store(-4);
    bst->Store(7);
    bst->Store(20);
    bst->Store(-96);
    bst->Store(55);

    bst->Display();
    delete bst;

    return 0;
}



