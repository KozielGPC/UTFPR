#include <stdio.h>
#include "../utils/utils.h"
#include <limits.h>

#define arrayLenght 10

void merge(int *array, int startLeftArrayIndex, int endLeftArrayIndex, int endRightArrayIndex)
{
    int leftArrayLenght = endLeftArrayIndex - startLeftArrayIndex + 1;
    int rightArrayLenght = endRightArrayIndex - endLeftArrayIndex;
    int leftArrayIndex, rightArrayIndex;
    int *leftArray = malloc(sizeof(int) * (leftArrayLenght + 1));
    int *rightArray = malloc(sizeof(int) * (rightArrayLenght + 1));

    for (leftArrayIndex = 0; leftArrayIndex < leftArrayLenght; leftArrayIndex++)
    {
        leftArray[leftArrayIndex] = array[startLeftArrayIndex + leftArrayIndex];
    }
    leftArray[leftArrayIndex] = INT_MAX;

    for (rightArrayIndex = 0; rightArrayIndex <= rightArrayLenght; rightArrayIndex++)
    {
        rightArray[rightArrayIndex] = array[endLeftArrayIndex + rightArrayIndex + 1];
    }
    rightArray[rightArrayLenght] = INT_MAX;

    rightArrayIndex = 0;
    leftArrayIndex = 0;

    for (int i = startLeftArrayIndex; i <= endRightArrayIndex; i++)
    {
        if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex])
        {
            array[i] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        }
        else
        {
            array[i] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int *array, int startLeftArrayIndex, int startRightArrayIndex)
{
    if (startLeftArrayIndex < startRightArrayIndex)
    {
        int halfIndex = (startLeftArrayIndex + startRightArrayIndex) / 2;
        mergeSort(array, startLeftArrayIndex, halfIndex);
        mergeSort(array, halfIndex + 1, startRightArrayIndex);
        merge(array, startLeftArrayIndex, halfIndex, startRightArrayIndex);
    }
}

int main(void)
{
    int array[arrayLenght] = {1, 2, 7, 3, 9, 0, 1, 10, 4, 5};
    printf("MergeSort \n");
    printArray(array, arrayLenght);
    mergeSort(array, 0, arrayLenght - 1);
    printArray(array, arrayLenght);
    return 0;
}