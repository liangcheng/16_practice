/**
 * O(n^2) for all cases, no more than n swap. not stable.
 */

#include <iostream>

using namespace std;

void Selection_sort(int arr[], int n);
int main();

void Selection_sort(int arr[], int n)
{
    int i,j,min_index, tmp;
    for(i=0; i<n-1;++i)
    {
        min_index = i;
        for(j=i+1; j<n;++j)
        {
            if (arr[j]<arr[min_index])
                min_index = j;
        }
        if(min_index !=i)
        {
            tmp =arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}



int main()
{
    int arr[5] = {5,1,12,-5,16};
    Selection_sort(arr, 5);

    for (int i=0; i<5; ++i)
        cout<< arr[i]<<"\n";

    return 0;
}
