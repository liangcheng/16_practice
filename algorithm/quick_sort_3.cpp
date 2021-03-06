#include <iostream>
#include <ctime>

void Quicksort(int* ipA, int iSize) {

    // Partitions of size 0 or 1 are already sorted
    if (iSize <= 1) {
        return;
    }

    // Select a pivot from the array randomly
    int iPivot = ipA[iSize/2];

    // Indices of the entries to be swapped
    int iLower = 0;
    int iUpper = iSize - 1;



    // Partition array into sections above and below the pivot
    while (iLower < iUpper) {

        while (ipA[iLower] < iPivot) {
            ++iLower;
        }

        while (ipA[iUpper] > iPivot) {
            --iUpper;
        }

        // Swap the entries at the lower and upper indices
        int iTemp       = ipA[iLower];
        ipA[iLower]     = ipA[iUpper];
        ipA[iUpper]     = iTemp;
    }



    // Recursively call partition on each partititon.
    Quicksort(ipA, iLower);
    Quicksort(&(ipA[iLower + 1]), iSize - iLower - 1);
}



int main() {
    using namespace std;

    int iaArray[] = {24, 5, 3, 35, 14, 23, 19, 43, 2};
    int iSize = 9;

    Quicksort(iaArray, iSize);

    // Output sorted array
    for (int i = 0; i < iSize; i++){
        cout << iaArray[i] << "  ";
    }
    cout << endl;

    return 0;
}
