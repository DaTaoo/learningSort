#include <iostream>
#include "InsertionSort.h"

using namespace std;


template <typename T>
void __mergeArr(T arr[], int l, int mid, int r)
{
    T aux[r - l + 1];
    for (int i = l; i <= r; i++)
    {
        aux[i - l] = arr[l];
    }

    int i = l;
    int j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] > aux[j - l])
        {
            arr[k] = aux[j - l];
            j++;
        }
        else
        {
            arr[k] = aux[i - l];
            i++;
        }
    }
}

/* 数组范围 [l,r] */
template <typename T>
void __divideArr(T arr[], int l, int r)
{
    //分到小规模之后直接使用插入排序
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r) / 2;

    __divideArr(arr, l, mid);
    __divideArr(arr, mid + 1, r);
    
    //对于近乎有序的数组非常有效
    if ( arr[mid] > arr[mid+1]) {
        __mergeArr(arr, l, mid, r);
    }

    return;
}

template <typename T>
void mergeSort(T arr[], int n)
{
    __divideArr(arr, 0, n - 1);
}
