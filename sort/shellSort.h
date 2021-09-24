#ifndef SHELLSORT_H
#define SHELLSORT_H

template <typename T>
void shellSort(T array[], int n)
{
    //shellSort = insertionSort with group
    int distance = 1;
    //扩大distance到最大
    while (distance < n / 3)
    {
        distance = 3 * distance + 1;
    }
    while (distance >= 1)
    {
        //[0,...,distance-1]为每个插入排序group的第一个，因此不用动
        for (int i = distance; i < n; i++)
        {
            T aux = array[i];
            int j;
            for (j = i - distance; j >= 0 && array[j] > aux; j = j - distance)
            {
                array[j + distance] = array[j];
            }
            array[j + distance] = aux;
        }
        //缩小group内的distance,直到 distance = 1, group退化为整个数组
        distance = distance / 3;
    }
}

#endif