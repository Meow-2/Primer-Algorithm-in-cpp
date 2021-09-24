#include "ArrayTools.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"

int main()
{
    int n = 40;
    randomArray testArray = randomArray(n, 0, n / 2);
    if (n <= 50)
        std::cout << testArray << std::endl;
    testArray.testSortAlgorithm(selectionSort, "selectionSort");
    testArray.testSortAlgorithm(insertionSort, "insertionSort");
    testArray.testSortAlgorithm(shellSort, "shellSort");
    testArray.testSortAlgorithm(mergeSort, "mergeSort");
    testArray.testSortAlgorithm(quickSort, "quickSort");
    return 0;
}
