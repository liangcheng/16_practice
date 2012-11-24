#include <iostream>

using namespace std;

int main()
{

    long double *p = new long double[10];

    cout <<sizeof(p) <<" , "<<sizeof(*p)<<endl;

    return 0;
}
