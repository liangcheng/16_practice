/**
 * bubble sort is a very simple sorting algorithm. the performance is O(n), O(n^2),
 * O(n^2) for best, average, worst cases, respectively. Memory usage is only O(1).
 */

#include <iostream>

using namespace std;

void Bubble_sort();
int main();

void Bubble_sort(int arr[], int n)
{
    bool swapped =true;
    int j=0, tmp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i=0;i< n-j; i++)
        {
            if (arr[i]>arr[i+1])
            {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true;
            }
        }
    }
};



int main()
{
    int arr[5] = {5,1,12,-5,16};
    Bubble_sort(arr, 5);

    for (int i=0; i<5; ++i)
        cout<< arr[i]<<"\n";

    return 0;
}
