#include <stdio.h>
#include "../utils/utils.h"

#define arrayLenght 10

void insertion(int *array, int maxIndex)
{
    int element = array[maxIndex];
    int i = maxIndex - 1;
    while ((i >= 0) && (array[i] > element))
    {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = element;
}

void insertionSort(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        insertion(array, i);
    }
}

int main(void)
{
    int array[arrayLenght] = {116, 298, 249, 411, 725, 717, 461, 97, 179, 57};
    printf("InsertionSort \n");
    printArray(array, arrayLenght);
    insertionSort(array, arrayLenght);
    printArray(array, arrayLenght);
    return 0;
}