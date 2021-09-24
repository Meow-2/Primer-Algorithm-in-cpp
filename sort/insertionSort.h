#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template <typename T>
void insertionSort(T array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        T aux = array[i];
        int j;
        for (j = i - 1; j >= 0 && array[j] > aux; j--)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = aux;
    }
}

#endif