#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// all position should be given according to zero indexed array
void insertion_sort(short arr[], int initial, int final)
{
    for (int i = initial; i <= final; i++)
    {
        int value = arr[i];
        int pos = i - 1;
        while (pos >= initial && arr[pos] > value)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = value;
    }
}

// all position should be given according to zero indexed array
int give_median(short arr[], int initial, int final)
{
    insertion_sort(arr, initial, final);
    int mid = (initial + final) / 2;
    return arr[mid];
}

//give arr_size as sizeof(arr)/sizeof(int)
int median_of_median(short arr[], int arr_size, int divide_size)
{
    if (arr_size < divide_size)
    {
        int median = give_median(arr, 0, arr_size - 1);
        return median;
    }

    int no_full_group = arr_size / divide_size;
    int elements_in_last = arr_size % divide_size;

    int next_arr_size;

    if (elements_in_last == 0)
        next_arr_size = no_full_group;
    else
        next_arr_size = no_full_group + 1;

    short next_arr[next_arr_size];

    for (int i = 0; i < next_arr_size; i++)
    {
        if (i == next_arr_size - 1)
            next_arr[i] = give_median(arr, divide_size * i, arr_size - 1);
        else
            next_arr[i] = give_median(arr, divide_size * i, divide_size * (i + 1) - 1);
    }

    return median_of_median(next_arr, next_arr_size, divide_size);
}

void text_to_arr(short *arr, int n)
{

    FILE *fin = fopen("./uniform_distribution.csv", "r");

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

    const int max_arr_size = 1e5;
    int divide_size = 5;
    int num_iter = 10;
    float start_time, end_time, time_taken;
    double avg_time;

    FILE *fout = fopen("MoM_uniform_obs.csv", "w");
    fprintf(fout, "arr_size,avg_time\n");

    for (int arr_size = 100; arr_size <= max_arr_size; arr_size+=100)
    {
        short arr[arr_size];
        avg_time = 0;

        for (int i = 0; i < num_iter; i++)
        {
            text_to_arr(arr,arr_size);

            start_time = clock();
            int temp = median_of_median(arr, arr_size, divide_size);
            end_time = clock();

            time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            avg_time += time_taken;
        }

        avg_time = avg_time / num_iter;

        printf("array_size: %6d avg_time: %.5f ms\n", arr_size, avg_time);
        fprintf(fout, "%d,%f\n", arr_size, avg_time);
    }

    fclose(fout);
    return 0;
}