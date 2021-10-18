#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

//递归写法
template <typename T>
int binarySearch(T arr[], int n, T target)
{
    int mid = n / 2;
    if (n == 0)
        return -1;
    else if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
    {
        return binarySearch(arr + mid + 1, n - mid - 1, target);
    }
    else
    {
        return binarySearch(arr, mid, target);
    }
}

//循环写法
template <typename T>
int binarySearch(T arr[], int n, T target)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        //int mid = (l + r) / 2;            //两个很大int型相加有可能溢出，所以使用下面的写法
        int mid = l + (l - r) / 2;
        if (arr[mid] == T)
            return mid;
        else if (arr[mid] < T)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return -1;
}

#endif