#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

int insertion_sort(uint32_t arr[], int n);
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
    double Starttime, Endtime, resulttime;
    uint32_t arr[1000000]; // Объявляем массив фиксированного размера 200 000

    int sizes[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000, 850000, 900000, 950000, 1000000}; // Массив с размерами массивов для генерации

    for (int k = 0; k < 20; k++)
    {
        Starttime = wtime();
        int n = sizes[k]; // Выбираем размер массива из sizes

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

        insertion_sort(arr, n);

        // printf("Sorted array of size %d:\n", n);
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%4d,", arr[i]);
        // }
        // printf("\n");

        Endtime = wtime();
        resulttime = Endtime - Starttime;
        printf("Program execution time for array of size %d = %f seconds\n", n, resulttime);
    }

    return 0;
}

int insertion_sort(uint32_t arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}
