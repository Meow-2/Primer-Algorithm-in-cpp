#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <ctime>
#include <algorithm>
#include "insertionSort.h"
template <typename T>
void lessLGreaterR(T array[], int n, int &p0, int &p1)
{
    int indexL = 0; //less
    int indexG = n; //greater
    int indexE = 1; //equal
    /*左边小和等于，右边大，三路快排   
    [0,..,indexL] < array[0]
    (indexL,..,indexE) = array[0]
    [indexG,..,n-1] > array[0]*/
    while (indexE < indexG)
    {
        if (array[indexE] < array[0])
        {
            indexL++;
            std::swap(array[indexL], array[indexE]);
            indexE++;
        }
        if (array[indexE] == array[0])
        {
            indexE++;
        }
        if (array[indexE] > array[0])
        {
            indexG--;
            std::swap(array[indexE], array[indexG]);
        }
    }
    std::swap(array[0], array[indexL]);
    indexL--;
    p0 = indexL;
    p1 = indexG;
}

template <typename T>
void quickSort(T array[], int n)
{
    if (n < 10)
        insertionSort(array, n);
    else
    {
        // srand(time(NULL));
        int randElement = rand() % n;
        std::swap(array[0], array[randElement]);
        int p0, p1;
        lessLGreaterR(array, n, p0, p1);
        quickSort(array, p0 + 1);
        quickSort(array + p1, n - p1);
    }
}

#endif