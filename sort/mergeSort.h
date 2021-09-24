#ifndef MERGESORT_H
#define MERGESORT_H

#include "insertionSort.h"
template <typename T>
void merge(T array[], int halfN, int n)
{
    T *aux = new T[n];
    int indexL = 0;
    int indexR = halfN;
    for (int i = 0; i < n; i++)
    {
        if (indexL >= halfN)
        {
            aux[i] = array[indexR];
            indexR++;
        }
        else if (indexR >= n)
        {
            aux[i] = array[indexL];
            indexL++;
        }
        else if (array[indexL] <= array[indexR])
        {
            aux[i] = array[indexL];
            indexL++;
        }
        else if (array[indexL] > array[indexR])
        {
            aux[i] = array[indexR];
            indexR++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = aux[i];
    }
    delete[] aux;
}

template <typename T>
void mergeSort(T array[], int n)
{
    if (n < 10)
        insertionSort(array, n); //小规模排序,insertionSort比较有优势
    else
    {
        int halfN = n / 2;
        mergeSort(array, halfN);
        mergeSort(array + halfN, n - halfN);
        merge(array, halfN, n);
    }
}
#endif