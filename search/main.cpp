#include "binarySearch.h"
#include "BinarySearchTree.h"
#include <iostream>
int main()
{
    int a[] = {1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i <= 8; i++)
    {

        int floorIndex = floor(a, n, i);
        std::cout << "the floor index of " << i << " is " << floorIndex << ".";
        if (floorIndex >= 0 && floorIndex < n)
            std::cout << "The value is " << a[floorIndex] << ".";
        std::cout << std::endl;

        int ceilIndex = ceil(a, sizeof(a) / sizeof(int), i);
        std::cout << "the ceil index of " << i << " is " << ceilIndex << ".";
        if (ceilIndex >= 0 && ceilIndex < n)
            std::cout << "The value is " << a[ceilIndex] << ".";
        std::cout << std::endl;

        std::cout << std::endl;
    }
    BST<int, int> a0;
    return 0;
}