#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int DATASET_SIZE = 10e6;

void merge(int *arr, int initial, int mid, int final, long *count)
{
    int size1 = mid - initial + 1;
    int arr1[size1];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[initial + i];
        (*count)++;
    }

    int size2 = final - mid;
    int arr2[size2];

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
        (*count)++;
    }

    int arr1_pos = 0;
    int arr2_pos = 0;
    int arr_pos = initial;

    while (arr1_pos < size1 && arr2_pos < size2)
    {
        if (arr1[arr1_pos] < arr2[arr2_pos])
        {
            arr[arr_pos] = arr1[arr1_pos];
            arr1_pos++;
            arr_pos++;
            (*count)++;
        }
        else
        {
            arr[arr_pos] = arr2[arr2_pos];
            arr2_pos++;
            arr_pos++;
            (*count)++;
        }
        (*count) += 2;
    }

    while (arr1_pos < size1)
    {
        arr[arr_pos] = arr1[arr1_pos];
        arr1_pos++;
        arr_pos++;
        (*count)++;
    }

    while (arr2_pos < size2)
    {
        arr[arr_pos] = arr2[arr2_pos];
        arr2_pos++;
        arr_pos++;
        (*count)++;
    }
}

//sorts array of int type in ascending order, put initial as 0, and final as size -1
void merge_sort(int *arr, int initial, int final, long *count)
{
    if (initial < final)
    {
        int mid = (initial + final) / 2;
        merge_sort(arr, initial, mid, count);
        merge_sort(arr, mid + 1, final, count);
        merge(arr, initial, mid, final, count);
    }
}

//assuming 1 is true, 0 is false
int is_array_sorted(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

void text_to_arr(int *arr, int n)
{

    FILE *fin = fopen("./normal_distribution.csv", "r");

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        int skip_line = rand() % 10;

        for (int j = 0; j < skip_line; j++)
            fscanf(fin, "%d\n", &temp);

        fscanf(fin, "%d\n", &temp);
        arr[i] = temp;
    }
}

void main()
{
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        int n = floor(pow(2, 3));
        int a[n];

        text_to_arr(a, n);

        // for (int i = 0; i < n; i++)
        //     printf("%d ", a[i]);
        // printf("\n");

        long count = 0;
        // float start_time = clock();
        merge_sort(a, 0, n - 1, &count);
        // float end_time = clock();

        // for (int i = 0; i < n; i++)
        //     printf("%d ", a[i]);
        // printf("\n\n");

        if (is_array_sorted(a, sizeof(a) / sizeof(int)) == 1)
            // printf("Run %d: %0.4fms\n", i + 1, (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
            printf("Run %d: %ld comparisions\n", i + 1, count);
        else
        {
            printf("Array Not Sorted\n");
            break;
        }
    }
}