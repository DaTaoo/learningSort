#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"

using namespace std;

int main()
{
    int n = 100000;

    // int *arr = SortTestHelper::generateNearlyOrderedArray(n, 50);
    // SortTestHelper::printArray(arr, n);

    // int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    // SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);

    // int *arr2 = SortTestHelper::generateRandomArray(n, 0, n);
    // SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    // int *arr3 = SortTestHelper::generateRandomArray(n, 0, n);
    // SortTestHelper::testSort("Insertion Sort(Original Version):", insertionSort_OriginalVersion, arr3, n);

    // int *arr4 = SortTestHelper::generateRandomArray(n, 0, n);
    // SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);

    int *arr5 = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr5, n);

    int *arr6 = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr6, n);

    std::cin.get();

    // delete [] arr1;
    // delete [] arr2;
    //delete [] arr4;
    delete [] arr5;
    delete [] arr6;

    return 0;
}