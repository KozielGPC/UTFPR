#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#pragma once

int findMaxValueIndex(int *array, int lenght)
{
    int maxValueIndex = 0;
    for (int i = 0; i <= lenght; i++)
    {
        if (array[i] >= array[maxValueIndex])
        {
            maxValueIndex = i;
        }
    }
    return maxValueIndex;
}

void switchPosition(int *array, int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

void printArray(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}