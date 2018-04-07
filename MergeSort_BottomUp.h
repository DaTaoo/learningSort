#include <iostream>
#include "MergeSort.h"

using namespace std;

template <typename T>
void mergeSortBottomUp(T arr[], int n) {
    for (int size = 1; size <= n; size += size) {
        for (int i = 0; i + size < n; i += size + size) {
            __mergeArr(arr, i, i + size - 1, min(i + size + size - 1, n - 1);
        }
    }
}