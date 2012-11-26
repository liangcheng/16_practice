/**
 * good for small list/array. simple algorithm. O(n), o(n^2), O(n^2).
 **/
#include <iostream>

using namespace std;

void Insertion_sort(int arr[], int n)
{
    int tmp, j;
    for(int i=1; i<n;++i)
    {
        j =i;
        while(j>0 && arr[j-1]> arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] =tmp;
            j--;
        }
    }
};


int main()
{
    int arr[5] = {5,1,12,-5,16};
    Insertion_sort(arr, 5);

    for (int i=0; i<5; ++i)
        cout<< arr[i]<<"\n";

    return 0;
}

