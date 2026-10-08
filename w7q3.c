#include <stdio.h>
#include <omp.h>

#define N 1000000

int main()
{
    int A[N], B[N];
    long long dot_product = 0;

    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
        B[i] = i + 1;
    }

    #pragma omp parallel for reduction(+:dot_product)
    for (int i = 0; i < N; i++)
    {
        dot_product += (long long)A[i] * B[i];
    }

    printf("Dot Product = %lld\n", dot_product);

    return 0;
}