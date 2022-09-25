#include <stdio.h>
#include "../utils/utils.h"
#define arrayLenght 6

int partition(int *array, int start, int end)
{
    int element = array[end];
    int minorIndex = start - 1, largerIndex = start;
    for (largerIndex; largerIndex < end; largerIndex++)
    {
        if (array[largerIndex] <= element)
        {
            minorIndex++;
            switchPosition(array, minorIndex, largerIndex);
        }
    }
    switchPosition(array, minorIndex + 1, end);
    return minorIndex + 1;
}

void quickSort(int *array, int start, int end)
{
    int elementIndex;
    if (start < end)
    {
        elementIndex = partition(array, start, end);
        quickSort(array, start, elementIndex - 1);
        quickSort(array, elementIndex + 1, end);
    }
}

int main()
{
    int array[arrayLenght] = {-34, 1, 2, 2, 157, -213};
    printf("QuickSort \n");
    printArray(array, arrayLenght);
    quickSort(array, 0, arrayLenght - 1);
    printArray(array, arrayLenght);
    return 0;
}