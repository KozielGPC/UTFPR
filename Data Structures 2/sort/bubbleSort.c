#include <stdio.h>
#include "../utils/utils.h"

#define arrayLenght 6

void bubbleSort(int *array, int lenght)
{
    for (int i = lenght - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] >= array[j + 1])
            {
                switchPosition(array, j, j + 1);
            }
        }
    }
}

int main(void)
{
    int array[arrayLenght] = {0, 4, 2, 3, 7, 1};
    printf("BubbleSort \n");
    printArray(array, arrayLenght);
    bubbleSort(array, arrayLenght);
    printArray(array, arrayLenght);
    return 0;
}