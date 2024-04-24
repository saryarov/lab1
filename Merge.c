#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

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

void merge(uint32_t arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(uint32_t arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    double Starttime, Endtime, resulttime;
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

        mergeSort(arr, 0, n - 1);

        // printf("Sorted array of size %d:\n", n);
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%4d,", arr[i]);
        printf("\n");
        Endtime = wtime();
        resulttime = Endtime - Starttime;
        printf("Program execution time for array of size %d = %f seconds\n", n, resulttime);
    }
    return 0;
}
