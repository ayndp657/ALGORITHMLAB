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

int main()
{
    srand(time(0));

    int max_arr_size = 100000;
    int num_iter = 10;
    float start_time, end_time, time_taken;
    double avg_time;

    double time_obs[4];

    FILE *fout = fopen("MoM_obs.csv", "w");
    fprintf(fout, "num_elements,partition_3,partition_5,partition_7,partition_9\n");

    for (int arr_size = 100; arr_size <= max_arr_size; arr_size +=100)
    {
        short arr[arr_size];

        for (int obs_counter = 0; obs_counter <= 3; obs_counter++)
        {
            int divide_size = 2 * obs_counter + 3;
            avg_time = 0;

            if (divide_size == 7 && arr_size == 64)
                printf("Test2");

            for (int i = 0; i < num_iter; i++)
            {
                for (int j = 0; j < arr_size; j++)
                    arr[j] = rand() % 100;

                start_time = clock();
                int temp = median_of_median(arr, arr_size, divide_size);
                end_time = clock();

                time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;

                printf("Num: %d divide_size: %d time: %0.4fms\n", arr_size, divide_size, time_taken);

                avg_time += time_taken;
            }

            avg_time = avg_time / num_iter;
            time_obs[obs_counter] = avg_time;
        }

        fprintf(fout, "%d,%f,%f,%f,%f\n", arr_size, time_obs[0], time_obs[1], time_obs[2], time_obs[3]);
    }

    fclose(fout);
    return 0;
}