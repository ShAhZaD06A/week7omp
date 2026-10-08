#include <stdio.h>
#include <omp.h>

#define N 100000000

long long arr[N];

int main()
{
    for (long long i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    long long serial_sum = 0;

    double start = omp_get_wtime();

    for (long long i = 0; i < N; i++)
    {
        serial_sum += arr[i];
    }

    double end = omp_get_wtime();

    printf("\nSerial Sum = %lld\n", serial_sum);
    printf("Serial Time = %.6f seconds\n", end - start);

    long long critical_sum = 0;

    start = omp_get_wtime();

    #pragma omp parallel for
    for (long long i = 0; i < N; i++)
    {
        #pragma omp critical
        {
            critical_sum += arr[i];
        }
    }

    end = omp_get_wtime();

    printf("\nCritical Sum = %lld\n", critical_sum);
    printf("Critical Time = %.6f seconds\n", end - start);

    long long atomic_sum = 0;

    start = omp_get_wtime();

    #pragma omp parallel for
    for (long long i = 0; i < N; i++)
    {
        #pragma omp atomic
        atomic_sum += arr[i];
    }

    end = omp_get_wtime();

    printf("\nAtomic Sum = %lld\n", atomic_sum);
    printf("Atomic Time = %.6f seconds\n", end - start);

    long long parallel_sum = 0;

    start = omp_get_wtime();

    #pragma omp parallel for reduction(+:parallel_sum)
    for (long long i = 0; i < N; i++)
    {
        parallel_sum += arr[i];
    }

    end = omp_get_wtime();

    printf("\nReduction Sum = %lld\n", parallel_sum);
    printf("Reduction Time = %.6f seconds\n", end - start);

    return 0;
}