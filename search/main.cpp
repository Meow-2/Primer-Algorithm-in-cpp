#include "binarySearch.h"
#include <iostream>
int main()
{
    int a[2] = {0, 1};
    int b = binarySearch(a, 2, 1);
    std::cout << b << std::endl;
    return 0;
}