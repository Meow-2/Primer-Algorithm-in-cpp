#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "heap.h"

template <typename T, typename T1 = MaxHeap<T>>
void heapSort(T array[], int n)
{
    T1 maxHeap = T1(array, n, n);
    //用于测试insert()
    // T1 maxHeap = T1(n);
    // for (int i = 0; i < n; i++)
    // {
    //     maxHeap.insert(i, array[i]);
    // }
    for (int i = n - 1; i >= 0; i--)
    {
        array[i] = maxHeap.extractMax();
    }
}

template <typename T>
void shiftDownLocal(T array[], int k, int count)
{
    T aux = array[k];
    while (2 * k + 1 <= count - 1)
    {
        int j = 2 * k + 1;
        if (j + 1 <= count - 1 && array[j + 1] > array[j])
            j += 1;
        if (aux < array[j])
        {
            array[k] = array[j];
            k = j;
        }
        else
            break;
    }
    array[k] = aux;
}

template <typename T>
void heapSortLocal(T array[], int n)
{ //原地堆排序需要注意的问题就是，数字编号是从零开始的，子节点就是，2k+1和2k+2，父节点就是(k+1)/2 -1
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        shiftDownLocal(array, i, n);
    }
    for (int i = 0; i < n; i++)
    {
        std::swap(array[0], array[n - 1 - i]);
        shiftDownLocal(array, 0, n - 1 - i);
    }
}
#endif
