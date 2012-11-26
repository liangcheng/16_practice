/**
divid and conquer. choose pivot value, partition, sort both part.
log(n) space usage.
O(nlogn), O(nlogn), O(n^2).
Time complexity of this method depends upon the sorting technique
used. In the above implementation, quickSort is used which may be
O(n^2) in worst case. If we use a O(nLogn) sorting algorithm
like merge sort, then the complexity becomes O(nLogn).

**/


#include <iostream>

using namespace std;

void Quick_sort(int arr[], int left, int right, int scratch[])
{
    int i=left, j=right;
    int tmp;
    int pivot = arr[(left+right)/2];

    //partition
    while (i<=j)
    {
        while (arr[i]<pivot)
            i++;
        while (arr[j]>pivot)
            j--;

        if(i <=j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    //recursion
    if (left<j)
        Quick_sort(arr, left, j);
    if (right >i)
        Quick_sort(arr, i, right);
};

int main()
{
    int arr[9] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
    Quick_sort(arr, 0,8);

    for(int i=0; i<9; ++i)
        cout << arr[i]<<"\n";

    return 0;
}
