#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <algorithm>
template <typename T>
void selectionSort(T array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        std::swap(array[minIndex], array[i]);
    }
}

#endif
