#include <iostream>

using namespace std;


template <typename T>
T template_sum(T *array, int size)
{
    int i;
    T sum = 0;
    for(i=0; i<size; i++)
    {
        sum += array[i];
    }
    return sum;
}


template <class C>
C class_sum(C *array, int size)
{
    int i;
    C sum = 0;
    for(i=0; i<size; i++)
    {
        sum += array[i];
    }
    return sum;
}



int main()
{
    int ia[5] = {5,1,7,3,10};
    double da[4] = {1.22,3.51,8.02,5.78};

    cout<<template_sum(ia, 5)<<endl;
    cout<<template_sum(da, 4)<<endl;

    cout<<class_sum(ia, 5)<<endl;
    cout<<class_sum(da, 4)<<endl;
    return 0;
}

