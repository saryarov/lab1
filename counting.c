#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

int foo(int *pmax, int *pmin, int n, uint32_t A[]);
int max_min(int *pmax, int *pmin, uint32_t A[], int n);
int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    double Starttime, Endtime, result;

    int min = 0, max = 0;
    int *pmin = &min;
    int *pmax = &max;

    uint32_t arr[1000000];

    int sizes[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000, 850000, 900000, 950000, 1000000};
    for (int k = 0; k < 20; k++)
    {
        Starttime = wtime();
        int n = sizes[k];

        for (int i = 0; i < n; i++)
        {
            arr[i] = getrand(0, 100001) % 100001;
        }

        // printf("Unsorted array of size %d:\n", n);
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%4d,", arr[i]);
        // }

        printf("\n");

        max_min(pmax, pmin, arr, n);

        // printf("min: %d, max: %d\n", min, max);

        foo(pmax, pmin, n, arr);

        // printf("Sorted array of size %d:\n", n);
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%4d,", arr[i]);
        // }
        printf("\n");
        Endtime = wtime();
        result = Endtime - Starttime;
        printf("Program execution time for array of size %d = %f seconds\n", n, result);
    }

    return 0;
}

int foo(int *pmax, int *pmin, int n, uint32_t A[])
{

    uint32_t C[*pmax - *pmin + 1];
    for (int i = 0; i < *pmax - *pmin + 1; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        C[A[i] - *pmin]++;
    }
    for (int i = 0, a = 0; i < *pmax - *pmin + 1; i++)
    {
        for (int j = 0; j < C[i]; j++)
        {
            A[a++] = i + *pmin;
        }
    }
    return 0;
}

int max_min(int *pmax, int *pmin, uint32_t A[], int n)
{
    *pmax = A[0];
    *pmin = A[0];
    for (int i = 1; i < n; i++)
    {
        if (*pmin > A[i])
        {
            *pmin = A[i];
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (*pmax < A[i])
        {
            *pmax = A[i];
        }
    }
    return 0;
}
