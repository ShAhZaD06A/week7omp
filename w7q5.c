#include <stdio.h>
#include <omp.h>

#define N 1000

int main()
{
    static int A[N][N], B[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = i * N + j;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[j][i] = A[i][j];
        }
    }

    printf("Matrix A:\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B (Transpose):\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}