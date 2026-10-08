#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

#define N 1000000

int main()
{
    int arr[N];
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 1000000;
    }
    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    #pragma omp parallel for reduction(min:min_val)
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    printf("Maximum Value = %d\n", max_val);
    printf("Minimum Value = %d\n", min_val);

    return 0;
}