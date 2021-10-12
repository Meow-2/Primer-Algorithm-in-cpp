#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include <cassert>
#include <algorithm>

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
    MaxHeap(Item arr[], int n, int capacity) : capacity(capacity), count(n)
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
        shiftDown(1);
        return data[count--];
    }
    void show();
};

template <typename Item>
void MaxHeap<Item>::show()
{
}
template <typename Item>
void MaxHeap<Item>::shiftUp(int k)
{
    Item aux = data[k];
    while (k / 2 >= 1 && data[k / 2] < aux)
    { //当节点k有父节点时
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
            data[k] = data[j];
        else
            break;
        k *= 2;
    }
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
#endif
