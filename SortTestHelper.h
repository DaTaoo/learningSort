#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

namespace SortTestHelper
{
/*生成有n个元素的随机数组，范围为[rangeL,rangeR]*/
int *generateRandomArray(int n, int rangeL, int rangeR)
{
    int *arr = new int[n];

    assert(rangeL <= rangeR);

    //时间设为随机种子
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return arr;
}

/*生成有n个元素的数组，数组元素大体排好序，但有 swapTimes 个元素随机交换了位置*/
int *generateNearlyOrderedArray(int n, int swapTimes) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    srand(time(NULL));

    for (int i = 0; i < swapTimes; i++) {
        int posX = rand() % n;
        int posY = rand() % n;
        swap(arr[posX], arr[posY]);
    }

    return arr;
}

/*打印数组*/
template <typename T>
void printArray(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/*复制数组*/
int* copyIntArray(int arr[], int n) {
    int *newArr = new int[n];
    
    copy(arr, arr+n, newArr);
    
    return newArr;
}

/*检查数组是否排好序*/
template <typename T>
bool isSorted(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

/*测试算法所用时间*/
template <typename T>
void testSort(std::string sortName, void (*sort)(T[], int), T arr[], int n)
{
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    std::cout << "is sorted? " << (isSorted(arr, n) ? "true" : "false") << std::endl;

    std::cout << sortName << ": " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;

    return;
}
}

#endif