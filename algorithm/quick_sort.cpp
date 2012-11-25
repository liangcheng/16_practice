/** 
Time complexity of this method depends upon the sorting technique 
used. In the above implementation, quickSort is used which may be 
O(n^2) in worst case. If we use a O(nLogn) sorting algorithm 
like merge sort, then the complexity becomes O(nLogn).
**/

#include <stdio.h>
#include <string.h>

// Following functions (exchange and partition are needed for quickSort)
void exchange(char *a, char *b)
{
    char temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
 
int partition(char A[], int si, int ei)
{
    char x = A[ei];
    int i = (si - 1);
    int j;
 
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}
 
/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(char A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
 
/* Driver program to test to pront printDups*/
int main()
{
    char str1[] = "test";
    char str2[] = "ttew";
    if ( areAnagram(str1, str2) )
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");
 
    return 0;
}