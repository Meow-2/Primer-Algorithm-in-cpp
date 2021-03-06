#include "ArrayTools.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "bubbleSort.h"
#include "heapSort.h"

int main()
{
    int n = 1000000;
    int rangL = 0;
    int rangR = n / 2;
    randomArray testArray = randomArray(n, rangL, rangR);              //大规模含重复元素数组
    randomArray nearlyOrderArray = randomArray(n, rangL, rangR, true); //大规模含重复元素,几乎排好序的数组
    if (n <= 50)
    {
        std::cout << "testArray: " << testArray << std::endl;
        std::cout << "nearlyOrderArray: " << nearlyOrderArray << std::endl;
        std::cout << MaxHeap<int>(testArray.arrPtr(), n, n) << std::endl;
    }
    std::cout << "randomArray,range of (" << rangL << "," << rangR << ")" << std::endl;
    testArray.testSortAlgorithm(quickSort, "quickSort");
    testArray.testSortAlgorithm(heapSortLocal, "heapSortLocal");
    testArray.testSortAlgorithm(heapSort<int, MaxHeap<int>>, "heapSort");
    testArray.testSortAlgorithm(heapSort<int, IndexMaxHeap<int>>, "IndexMaxHeapSort");
    testArray.testSortAlgorithm(shellSort, "shellSort");
    testArray.testSortAlgorithm(mergeSort, "mergeSort");
    testArray.testSortAlgorithm(insertionSort, "insertionSort");
    testArray.testSortAlgorithm(selectionSort, "selectionSort");
    testArray.testSortAlgorithm(bubbleSort, "bubbleSort");
    std::cout << std::endl;
    std::cout << "nearlyOrderArray,range of (" << rangL << "," << rangR << ")" << std::endl;
    nearlyOrderArray.testSortAlgorithm(quickSort, "quickSort");
    nearlyOrderArray.testSortAlgorithm(heapSortLocal, "heapSortLocal");
    nearlyOrderArray.testSortAlgorithm(heapSort<int, MaxHeap<int>>, "heapSort");
    nearlyOrderArray.testSortAlgorithm(heapSort<int, IndexMaxHeap<int>>, "IndexMaxHeapSort");
    nearlyOrderArray.testSortAlgorithm(shellSort, "shellSort");
    nearlyOrderArray.testSortAlgorithm(mergeSort, "mergeSort");
    nearlyOrderArray.testSortAlgorithm(insertionSort, "insertionSort");
    nearlyOrderArray.testSortAlgorithm(selectionSort, "selectionSort");
    nearlyOrderArray.testSortAlgorithm(bubbleSort, "bubbleSort");
    return 0;
}
