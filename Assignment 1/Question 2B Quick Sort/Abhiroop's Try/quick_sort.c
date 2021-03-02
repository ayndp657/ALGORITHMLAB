#include <stdio.h>
#include <stdbool.h> //for true keyword
#include <stdlib.h>  //for rand() and srand()
#include <time.h>
#include <math.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *arr, int initial, int final)
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

        if (left_iterator < right_iterator && arr[left_iterator] != arr[right_iterator])
            swap(&arr[left_iterator], &arr[right_iterator]);
        else
            return left_iterator;
    }
}

//sorts array using quick_sort algorithm, give initial as 0, and final as sizeofarray -1
void quick_sort(int *arr, int initial, int final)
{
    if (initial < final)
    {
        int pos_of_pivot = partition(arr, initial, final);
        quick_sort(arr, initial, pos_of_pivot);
        quick_sort(arr, pos_of_pivot + 1, final);
    }
}

void main()
{

    srand(time(0));
    
    for (int i = 0; i < 1;i++)
    {
        int n = floor(pow(2,17));
        int a[n];
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100;

        float initial_time = clock();
        quick_sort(a, 0, n - 1);
        float final_time = clock();

        printf("Run %d: %0.4fms\n", i + 1, (final_time - initial_time) * 1000 / CLOCKS_PER_SEC);
    }
}