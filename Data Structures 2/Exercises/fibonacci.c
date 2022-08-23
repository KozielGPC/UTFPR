#include <stdio.h>
#include <stdint.h>

uint64_t fibonacci(int n, uint64_t *array)
{
    if (array[n] != 0)
        return array[n];
    uint64_t value = fibonacci(n - 1, array) + fibonacci(n - 2, array);
    array[n] = value;
    return value;
}

uint64_t fibonacci_m(int n)
{
    uint64_t *array = calloc(n + 1, sizeof(uint64_t));
    array[0] = 1;
    array[1] = 1;
    uint64_t response = fibonacci(n, array);
    free(array);
    return response;
}

int main(void)
{
    printf("Hello World\n");
    printf("%lu\n", fibonacci_m(5));
    return 0;
}