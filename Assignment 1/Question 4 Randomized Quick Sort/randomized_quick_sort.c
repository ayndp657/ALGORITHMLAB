#include <stdio.h>
#include <stdbool.h> //for true keyword
#include <stdlib.h>  //for rand() and srand()
#include <time.h>
#include <math.h>

void swap(short *a, short *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(short *arr, int initial, int final, int *count)
{
    int pivot_value = arr[initial];

    int left_iterator = initial;
    int right_iterator = final;

    while (true)
    {
        while (arr[left_iterator] < pivot_value)
            left_iterator++;

        while (pivot_value < arr[right_iterator])
            right_iterator--;

        if (arr[left_iterator] == arr[right_iterator])
        {
            if (left_iterator == right_iterator)
                return left_iterator;
            else
                right_iterator--;
        }
        else if (left_iterator < right_iterator)
        {
            swap(&arr[left_iterator], &arr[right_iterator]);
            (*count)++;
        }
        else
            return left_iterator;
    }
}

int randomized_partition(short *arr, int initial, int final, int *count)
{
    int i = rand() % (final - initial) + initial;
    swap(arr[initial], arr[i]);
    return partition(arr, initial, final, count);
}

//sorts array using quick_sort algorithm, give initial as 0, and final as sizeofarray -1
void quick_sort(short *arr, int initial, int final, int *count)
{
    if (initial < final)
    {
        int pos_of_pivot = randomized_partition(arr, initial, final, count);
        quick_sort(arr, initial, pos_of_pivot, count);
        quick_sort(arr, pos_of_pivot + 1, final, count);
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

int main()
{

    srand(time(0));

    int max_p = 20;
    int num_iter_power = 50;

    FILE *fout = fopen("random_quick_normal_obs.csv", "w");

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
            quick_sort(a, 0, n - 1, &count);
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

    return 0;
}