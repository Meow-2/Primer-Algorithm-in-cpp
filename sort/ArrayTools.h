#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H

#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
//用于测试的数组，希望一个数组能测试多个算法并进行比较
class randomArray
{
public:
    //[rangL,rangR]
    randomArray(int n, int rangeL, int rangR, bool nearlyOrder = false);
    ~randomArray() { delete arrayPtr; }
    //判断数组是否排序正确
    bool isCorrect(int *p, int n) const;
    //测试排序算法的时间和正确性
    void testSortAlgorithm(void (*sortFunc)(int[], int), char *p) const;

    friend std::ostream &operator<<(std::ostream &os, const randomArray &array)
    {
        for (int i = 0; i < array.arrayNum; i++)
            os << array.arrayPtr[i] << " ";
        return os;
    }

private:
    int arrayNum;
    int *arrayPtr; //指向int数组的指针
};

randomArray::randomArray(int n, int rangL, int rangR, bool nearlyOrder) : arrayNum(n)
{
    assert(rangL <= rangR);
    srand(time(NULL));
    arrayPtr = new int[n];
    if (!nearlyOrder)
        for (int i = 0; i < n; i++)
            arrayPtr[i] = rand() % (rangR - rangL + 1) + rangL;
    else
    {
        //生成几乎排好的数组，为了让数据尽量均匀分布，计算一个元素的重复次数
        int sameN = ceil((double)n / (rangR - rangL + 1));
        for (int i = 0; i < n; i++)
            arrayPtr[i] = rangL + (i + 1) / sameN;
        srand(time(NULL));
        for (int i = 0; i < n / 10; i++)
            std::swap(arrayPtr[rand() % n], arrayPtr[rand() % n]);
    }
}
bool randomArray::isCorrect(int *p, int n) const
{
    for (int i = 0; i + 1 < n; i++)
    {
        if (p[i] > p[i + 1])
            return false;
    }
    return true;
}

void randomArray::testSortAlgorithm(void (*sortFunc)(int[], int), char *p) const
{
    //创建临时数组用于排序，使原数组可以被多次利用
    int *aux = new int[arrayNum];
    for (int i = 0; i < arrayNum; i++)
        aux[i] = arrayPtr[i];
    clock_t begin = clock();
    sortFunc(aux, arrayNum);
    clock_t end = clock();
    double runTime = (double)(end - begin) / CLOCKS_PER_SEC;
    if (isCorrect(aux, arrayNum))
    {
        std::cout << "numbers: " << arrayNum << " ,time: " << runTime << " s";
    }
    else
    {
        std::cout << "Sort wrong.";
        if (arrayNum <= 50)
        {
            for (int i = 0; i < arrayNum; i++)
                std::cout << aux[i] << " ";
        }
        else
            std::cout << "Try numbers less than 50 to print sort result.";
    }
    std::cout << " ," << p << std::endl;
    delete[] aux;
};
#endif //ARRAYTOOLS_H