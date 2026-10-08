#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int main()
{
    float arr[ARRAY_SIZE];
    double total_sum = 0.0;
    double average;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = ((float)rand() / RAND_MAX) * 1000000.0f;
    }

    #pragma omp parallel for reduction(+:total_sum)
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        total_sum += arr[i];
    }

    average = total_sum / ARRAY_SIZE;

    printf("Average of array elements: %.6f\n", average);

    return 0;
}