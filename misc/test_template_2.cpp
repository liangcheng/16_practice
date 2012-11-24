#include <iostream>

using namespace std;

template <typename T, typename M, int size>
T sum(T (&a)[size], M second)
{
    int i;
    T total = 0;
    for(i=0; i<size; i++)
    {
        total += a[i];
    }
    total += second;
    return total;
}

int main()
{
    double da[5] = {1.22,4.01,5.00,3.27,7.87};
    int i = 200;
    cout<<sum(da, i)<<endl;
    return 0;
}
