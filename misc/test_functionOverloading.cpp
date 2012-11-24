#include <iostream>
#include <list>

using namespace std;
typedef list<int> LIST;
int get_max(LIST &list);
int get_max(int &x, int &y);

int main()
{
    LIST list;
    list.push_back(12);
    list.push_back(4);
    list.push_back(8);
    list.push_back(5);
    cout<<get_max(list)<<endl;
    int x = 120;
    int y = 121;
    cout<<get_max(x, y)<<endl;
    return 0;
}

int get_max(LIST &list)
{
    int max = 0;
    LIST::iterator it;
    for(it = list.begin(); it != list.end(); it++)
    {
        if(max<*it)
        {
            max = *it;
        }
    }
    return max;
}

int get_max(int &x, int &y)
{
    return x<y?y:x;
}

int getMax(int &x, int &y)
{
    return x<y?y:x;
}
