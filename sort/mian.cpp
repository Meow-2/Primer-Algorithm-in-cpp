#include "ArrayTools.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"

int main()
{
    int n = 100000;
    int rangL = 0;
    int rangR = n / 2;
    randomArray testArray = randomArray(n, rangL, rangR);              //大规模含重复元素数组
    randomArray nearlyOrderArray = randomArray(n, rangL, rangR, true); //大规模含重复元素,几乎排好序的数组
    // if (n <= 50)
    // {
    //     std::cout << "testArray: " << testArray << std::endl;
    //     std::cout << "nearlyOrderArray: " << nearlyOrderArray << std::endl;
    // }
    std::cout << "randomArray,range of (" << rangL << "," << rangR << ")" << std::endl;
    testArray.testSortAlgorithm(quickSort, "quickSort");
    testArray.testSortAlgorithm(shellSort, "shellSort");
    testArray.testSortAlgorithm(mergeSort, "mergeSort");
    testArray.testSortAlgorithm(insertionSort, "insertionSort");
    testArray.testSortAlgorithm(selectionSort, "selectionSort");
    std::cout << std::endl;
    std::cout << "nearlyOrderArray,range of (" << rangL << "," << rangR << ")" << std::endl;
    nearlyOrderArray.testSortAlgorithm(shellSort, "shellSort");
    nearlyOrderArray.testSortAlgorithm(quickSort, "quickSort");
    nearlyOrderArray.testSortAlgorithm(mergeSort, "mergeSort");
    nearlyOrderArray.testSortAlgorithm(insertionSort, "insertionSort");
    nearlyOrderArray.testSortAlgorithm(selectionSort, "selectionSort");
    return 0;
}
