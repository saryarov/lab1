#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void find_union(char set_A[], int size_A, char set_B[], int size_B, char result[], int size_result)
{
    int i, j;
    for (i = 0; i < size_A; i++)
    {
        result[i] = set_A[i];
    }

    for (i = 0; i < size_B; i++)
    {
        int found = 0;
        for (j = 0; j < size_A; j++)
        {
            if (set_B[i] == set_A[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            result[size_A++] = set_B[i];
        }
    }
}

void find_intersection(char set_A[], int size_A, char set_B[], int size_B, char result[], int size_result)
{
    int i, j;
    for (i = 0; i < size_B; i++)
    {
        int found = 0;
        for (j = 0; j < size_A; j++)
        {
            if (set_B[i] == set_A[j])
                result[i] = set_B[i];
        }
    }
}

void find_difference(char set_A[], int size_A, char set_B[], int size_B, char result[], int size_result)
{
    int i, j;
    int found;

    for (i = 0; i < size_A; i++)
    {
        found = 0;
        for (j = 0; j < size_B; j++)
        {
            if (set_A[i] == set_B[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            result[i] = set_A[i];
    }
}

void find_symmetric_difference(char set_A[], int size_A, char set_B[], int size_B, char result[], int size_result)
{
    int i, j;
    int found;
    for (i = 0; i < size_A; i++)
    {
        found = 0;
        for (j = 0; j < size_B; j++)
        {
            if (set_A[i] == set_B[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            result[i] = set_A[i];
    }

    for (i = 0; i < size_B; i++)
    {
        int found = 0;
        for (j = 0; j < size_A; j++)
        {
            if (set_B[i] == set_A[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            result[size_A++] = set_B[i];
    }
}

void find_second_difference(char set_A[], int size_A, char set_B[], int size_B, char result[], int size_result)
{
    int i, j;
    int found;

    for (i = 0; i < size_A; i++)
    {
        found = 0;
        for (j = 0; j < size_B; j++)
        {
            if (set_B[i] == set_A[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            result[i] = set_B[i];
    }
}

int main()
{
    char set_A[MAX_SIZE], set_B[MAX_SIZE], result[MAX_SIZE];
    int size_A, size_B, size_result;
    char choice;

    printf("Enter the elements of set A (Latin alphabet letters, no duplicates): ");
    scanf("%s", set_A);
    size_A = strlen(set_A);

    printf("Enter the elements of set B (Latin alphabet letters, no duplicates): ");
    scanf("%s", set_B);
    size_B = strlen(set_B);
    size_result = size_A + size_B;
    qsort(set_A, size_A, sizeof(char), strcmp);
    qsort(set_B, size_B, sizeof(char), strcmp);

    do
    {
        printf("\nChoose operation:\n");
        printf("1. A ⋃ B\n");
        printf("2. A ⋂ B\n");
        printf("3. A ⊆ B\n");
        printf("4. A / B\n");
        printf("5. A △ B\n ");
        printf("6. B / A\n");
        printf("7. B ⊆ A\n");
        printf("8. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            find_union(set_A, size_A, set_B, size_B, result, size_result);

            printf("Union A and B: ");

            for (int i = 0; i < size_result; i++)
                printf("%c ", result[i]);

            printf("\n");
            break;

        case '2':
            find_intersection(set_A, size_A, set_B, size_B, result, size_result);

            printf("Intersection A and B: ");

            for (int i = 0; i < size_result; i++)
                printf("%c ", result[i]);

            printf("\n");
            break;
        case '3':
            if (strstr(set_B, set_A) != NULL)
                printf("A in B\n");

            else
                printf("A not in B\n");

            break;

        case '4':
            find_difference(set_A, size_A, set_B, size_B, result, size_result);

            printf("Difference A and B: ");

            for (int i = 0; i < size_result; i++)
                printf("%c ", result[i]);

            printf("\n");
            break;

        case '5':
            find_symmetric_difference(set_A, size_A, set_B, size_B, result, size_result);

            printf("Difference A and B: ");

            for (int i = 0; i < size_result; i++)
                printf("%c ", result[i]);

            printf("\n");
            break;

        case '6':
            find_second_difference(set_A, size_A, set_B, size_B, result, size_result);

            printf("Difference B and A: ");

            for (int i = 0; i < size_result; i++)
                printf("%c ", result[i]);

            printf("\n");
            break;

        case '7':
            if (strstr(set_A, set_B) != NULL)
                printf("B in A\n");

            else
                printf("B not in A\n");

            break;

        case '8':
            printf("Exit.\n");
            break;

        default:
            printf("Incorrect. Try again.\n");
        }
    } while (choice != '8');

    return 0;
}
