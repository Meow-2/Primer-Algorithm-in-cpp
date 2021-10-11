#ifndef BUBBLE_H
#define BUBBLE_H
#include <algorithm>

template <typename T>
void bubbleSort(T array[], int n)
{
    bool flag = true;
    while (flag)
    {
        flag = !flag;
        for (int i = 0; i + 1 < n; i++)
        {
            if (array[i] > array[i + 1])
                std::swap(array[i], array[i + 1]);
            flag = true;
        }
        n--;
    }
}

#endif