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
int binarySearchCycle(T arr[], int n, T target)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        //int mid = (l + r) / 2;            //两个很大int型相加有可能溢出，所以使用下面的写法
        int mid = l + (l - r) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return -1;
}

template <typename T>
int floor(T arr[], int n, T target)
{
    //如果target小于arr所有的元素，则返回-1
    int l = -1, r = n - 1;
    //这里不能写等于，因为l在循环中是有可能不会变的，所以l = mid = midL = midR = r时就可能会死循环，也不需要写等于，因为l索引对应的元素是已经搜索过的
    while (l < r)
    {
        //当l = r - 1时，mid = r，这里不能让mid = l，因为后面l的变化值为midR,若midR = mid且arr[mid]<target，会陷入l值不变的死循环
        int mid = l + (r - l + 1) / 2;
        int midL = mid;
        int midR = mid;
        while (midL - 1 >= 0 && arr[midL - 1] == arr[midL])
            midL--;
        while (midR + 1 <= n - 1 && arr[midR + 1] == arr[midR])
            midR++;
        if (arr[mid] == target)
            return midL;
        else if (arr[mid] < target)
            l = midR;
        else
            r = midL - 1;
    }
    return l;
}

template <typename T>
int ceil(T arr[], int n, T target)
{
    //如果target大于arr所有的元素，则返回n
    int l = 0, r = n;
    //这里不能写等于，因为r在循环中是有可能不会变的，所以l = mid = midL = midR = r时就会死循环
    while (l < r)
    {
        //当l = r - 1时，mid = l，这里不能让mid = r，因为后面r的变化值为midL，若midL = mid且arr[mid]>target，会陷入r值不变的死循环
        int mid = l + (r - l) / 2;
        int midL = mid;
        int midR = mid;
        while (midL - 1 >= 0 && arr[midL - 1] == arr[midL])
            midL--;
        while (midR + 1 <= n - 1 && arr[midR + 1] == arr[midR])
            midR++;
        if (arr[mid] == target)
            return midR;
        else if (arr[mid] < target)
            l = midR + 1;
        else
            r = midL;
    }
    return r;
}
#endif