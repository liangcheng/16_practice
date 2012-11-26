/**
* merging already sorted list into a new sorted list. comparing every two elements.
worst case O(log(n)). divide and conque.
**/

#include <iostream>

using namespace std;

void Merge(int arr[], int left, int mid, int right, int helper[]);


void Merge_sort(int arr[], int left, int right, int helper[])
{
    if(left<right)
    {
        int middle = (left+right)/2;
        Merge_sort(arr, left, middle, helper);
        Merge_sort(arr, middle+1, right, helper);
        Merge(arr, left, middle, right, helper);
    }
};

void Merge(int arr[], int left, int mid, int right, int helper[])
{
    for(int i=left;i<=right;++i)
        helper[i] = arr[i];

        int helper_left = left;
        int helper_right = mid +1;
        int current = left;

        while(helper_left<=mid &&helper_right <=right)
        {
            if(helper[helper_left]<=helper[helper_right])
            {
                arr[current] = helper[helper_left];
                helper_left++;
            }
            else
            {
                arr[current] = helper[helper_right];
                helper_right++;
            }
            current++;

            int remaining = mid- helper_left;
            for(int i=0; i<=remaining; i++)
                arr[current+i] =helper[helper_left+i];
        }

};



int main()
{
    int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24};
    int num = sizeof(a)/sizeof(int);
    int helper[num];


    Merge_sort(a, 0,num-1, helper);

    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
