#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int DATASET_SIZE = 10e6;

void merge(short *arr, int initial, int mid, int final, int *count)
{
    int size1 = mid - initial + 1;
    int arr1[size1];
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[initial + i];

    int size2 = final - mid;
    int arr2[size2];

    for (int i = 0; i < size2; i++)
        arr2[i] = arr[mid + 1 + i];

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
void merge_sort(short *arr, int initial, int final, int *count)
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
int is_array_sorted(short *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

void text_to_arr(short *arr, int n)
{

    FILE *fin = fopen("./normal_distribution.csv", "r");

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        int skip_line = rand() % 10;

        for (int j = 0; j < skip_line; j++)
            fscanf(fin, "%d\n", &temp);

        fscanf(fin, "%d\n", &temp);
        arr[i] = (short)temp;
    }

    fclose(fin);
}

void main()
{
    srand(time(0));

    int max_p = 20;
    int num_iter_power = 100;

    FILE *fout = fopen("observation.csv", "w");

    fprintf(fout, "num_elements,avg_comparison,avg_time\n");

    int n = 2;
    for (int p = 0; p < max_p; p++)
    {
        long sum_count = 0;
        float sum_time = 0;

        for (int i = 0; i < num_iter_power; i++)
        {
            short a[n];

            text_to_arr(a, n);

            // for (int i = 0; i < n; i++)
            //     printf("%d ", a[i]);
            // printf("\n");

            int count = 0;

            float start_time = clock();
            merge_sort(a, 0, n - 1, &count);
            float end_time = clock();

            sum_count += count;

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            sum_time += time_taken;

            // for (int i = 0; i < n; i++)
            //     printf("%d ", a[i]);
            // printf("\n\n");

            if (is_array_sorted(a, sizeof(a) / sizeof(int)) == 1)
                printf("Num = %d Run %d: %d comparison, %0.4f ms\n", n, i + 1, count, time_taken);
            else
            {
                printf("Array Not Sorted\n");
                break;
            }
        }

        float avg_time = sum_time / num_iter_power;
        long avg_count = sum_count / num_iter_power;
        fprintf(fout, "%d,%ld,%0.4f\n", n, avg_count, avg_time);
        n *= 2;
    }

    fclose(fout);
}