#ifndef HEAP_H
#define HEAP_H
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
    void insert(int dummy, Item item) //dummy是一个假参数，为了配合IndexMaxHeap.insert()使用模板
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

template <typename Item>
class IndexMaxHeap
{
private:
    Item *data;   //最大堆数据
    int *index;   //数据的索引，用索引代替数据构建堆
    int *rev;     //记录索引在堆中的位置
    int count;    //当前堆中数据的个数
    int capacity; //索引堆的最大容量
    void changeIndex(int arrIndex, int arrData)
    { //使用该函数来改变index数组的内容，同时维护rev数组
        index[arrIndex] = arrData;
        rev[arrData] = arrIndex;
    }
    void shiftDown(int k);
    void shiftUp(int k);

public:
    IndexMaxHeap(int capacity) : capacity(capacity), count(0)
    {
        //为方便理解，以下的索引指的是Index里的内容，编号指的是数组的编号，所以Index存储的索引指的是data数组里Item的编号
        data = new Item[capacity];     //存储堆中的数据，从外部来看，数据应当是以一个普通数组的形式存在，所以data从零开始编号
        index = new int[capacity + 1]; //因为真正变成堆的是索引，索引从1开始计数，方便计算索引的父子节点
        rev = new int[capacity];       //索引的范围是[0,capacity)，故rev的容量为capacity即可
    }
    IndexMaxHeap(Item array[], int n, int capacity) : capacity(capacity), count(n)
    {
        data = new Item[capacity];     //存储堆中的数据，从外部来看，数据应当是以一个普通数组的形式存在，所以data从零开始编号
        index = new int[capacity + 1]; //因为真正变成堆的是索引，索引从1开始计数，方便计算索引的父子节点
        rev = new int[capacity];       //索引的范围是[0,capacity)，故rev的容量为capacity即可
        for (int i = 0; i < count; i++)
        {
            data[i] = array[i];
            changeIndex(i + 1, i);
        }
        for (int i = count / 2; i >= 1; i--)
        {
            shiftDown(i);
        }
    }
    ~IndexMaxHeap()
    {
        delete[] data;
        delete[] index;
        delete[] rev;
    }
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    Item extractMax()
    {
        assert(!isEmpty());
        int temp = index[1];
        changeIndex(1, index[count]);
        changeIndex(count, temp);
        count--;
        shiftDown(1);
        return data[index[count + 1]];
    }
    void insert(int k, Item item)
    {
        assert(k < capacity);
        data[k] = item;
        count++;
        changeIndex(count, k);
        shiftUp(count);
    }
};

template <typename Item>
void IndexMaxHeap<Item>::shiftDown(int k)
{
    Item aux = index[k]; //与插入排序相似的操作，先申请一个辅助空间
    while (2 * k <= count)
    { //若存在子树
        int j = 2 * k;
        if (j + 1 <= count && data[index[j + 1]] > data[index[j]])
            j += 1;
        if (data[aux] >= data[index[j]])
            break;
        else
        {
            changeIndex(k, index[j]);
            k = j;
        }
    }
    changeIndex(k, aux);
}

template <typename Item>
void IndexMaxHeap<Item>::shiftUp(int k)
{
    Item aux = index[k];
    while (k / 2 >= 1 && data[index[k / 2]] < data[aux])
    {
        changeIndex(k, index[k / 2]);
        k /= 2;
    }
    changeIndex(k, aux);
}
#endif