#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
template <typename Item>
class MaxHeap
{
private:
    Item *data;   //堆
    int count;    //节点个数
    int capacity; //最大容量
    void shiftUp(int);
    void shiftDown(int);

public:
    MaxHeap(int capacity) : capacity(capacity), count(0)
    {
        data = new Item[capacity + 1];
    }
    MaxHeap(const Item arr[], int n, int capacity) : capacity(capacity), count(n)
    {
        data = new Item[capacity + 1];
        for (int i = 1; i <= n; i++)
        {
            data[i] = arr[i - 1];
        }
        for (int i = count / 2; i >= 1; i--)
        {
            shiftDown(i);
        }
    }
    ~MaxHeap() { delete[] data; }
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    void insert(Item item)
    {
        assert(count < capacity);
        data[++count] = item;
        shiftUp(count);
    }
    Item extractMax()
    {
        assert(!isEmpty());
        std::swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return data[count + 1];
    }
    std::ostream &show(std::ostream &os) const;
    friend std::ostream &operator<<(std::ostream &os, const MaxHeap &maxHeap)
    {
        return maxHeap.show(os);
    }
};
template <typename T>
std::ostream &printNum(std::ostream &os, int n, T item)
{
    for (int i = 0; i < n; i++)
        os << "  ";
    os << item;
    if (typeid(item).name() == "int" && item > 10)
        os << ' ';
    for (int i = 0; i < n; i++)
        os << "  ";
    os << "  ";
    return os;
}

template <typename Item>
std::ostream &MaxHeap<Item>::show(std::ostream &os) const
{
    int h = log2(count);          //层数，从零开始
    int lastFloor = pow(2, h);    //最后一层能容纳的最大数量
    int blankNum = lastFloor - 1; //第一层应打印的空格数
    int rest = count;             //堆剩余元素的数量
    for (int i = 0; i <= h; i++)
    {
        int j;
        for (j = 0; j < fmin(rest, pow(2, i)); j++)
        {
            printNum(os, blankNum, data[(int)pow(2, i) + j]);
        }
        os << std::endl;
        blankNum /= 2;
        rest -= j;
    }
    return os;
}

template <typename Item>
void MaxHeap<Item>::shiftUp(int k)
{
    Item aux = data[k];
    while (k / 2 >= 1 && data[k / 2] < aux)
    { //当节点k有父节点,且父节点小于子节点时
        data[k] = data[k / 2];
        k /= 2;
    }
    data[k] = aux;
}
template <typename Item>
void MaxHeap<Item>::shiftDown(int k)
{
    Item aux = data[k];
    while (2 * k <= count)
    { //当节点k有子树时,只需要选出子树节点中最大的节点与父节点比较就行，比父节点大的话就上去
        int j = 2 * k;
        if (j + 1 <= count && data[j + 1] > data[j])
            j += 1;
        if (data[j] > aux)
        {
            data[k] = data[j];
            k = j;
        }
        else
            break;
    }
    data[k] = aux;
}

template <typename T>
void heapSort(T array[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(array, n, n);
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
