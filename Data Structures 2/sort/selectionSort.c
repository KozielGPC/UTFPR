#include <stdio.h>
#include "../utils/utils.h"

#define arrayLenght 1

void selectionSort(int *array, int minIndex, int maxIndex)
{
    int maxValueIndex;
    for (int i = maxIndex - 1; i > 0; i--)
    {
        maxValueIndex = findMaxValueIndex(array, i);
        switchPosition(array, maxValueIndex, i);
    }
}

int main(void)
{
    int array[arrayLenght] = {0};
    printArray(array, arrayLenght);
    selectionSort(array, 0, arrayLenght);
    printArray(array, arrayLenght);
    return 0;
}