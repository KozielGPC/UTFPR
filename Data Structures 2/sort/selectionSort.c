#include <stdio.h>
#include "../utils/utils.h"

#define arrayLenght 1

void selectionSort(int *array, int lenght)
{
    int maxValueIndex;
    for (int i = lenght - 1; i > 0; i--)
    {
        maxValueIndex = findMaxValueIndex(array, i);
        switchPosition(array, maxValueIndex, i);
    }
}

int main(void)
{
    int array[arrayLenght] = {0};
    printf("SelectionSort \n");
    printArray(array, arrayLenght);
    selectionSort(array, arrayLenght);
    printArray(array, arrayLenght);
    return 0;
}