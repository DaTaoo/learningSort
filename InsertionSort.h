#include <iostream>

using namespace std;

/*
    优化后的插入排序
*/
template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

/*
    原始版本插入排序
*/
template <typename T>
void insertionSort_OriginalVersion(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            swap(arr[j], arr[j-1]);
        }
    }
}

template <typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i < r; i ++) {
        T e = arr[i];
        int j;
        for (j = i; j < r && arr[j-1] > e ; j--) {
            arr[j] = arr[j-1];
        } 
        arr[j] = e;
    }
}
