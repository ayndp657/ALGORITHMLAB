#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct LL
{
    float data;
    struct LL *next;
} node;

node *LL_insert_sorted(node *list, float d, int *count)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = d;

    if (list == NULL)
    {
        list = new_node;
        (*count)++;
    }
    else if (new_node->data < list->data)
    {
        new_node->next = list;
        list = new_node;
        (*count)++;
    }
    else
    {
        node *temp = list;

        while ((temp->next != NULL) && (!((temp->data <= new_node->data) && ((temp->next)->data >= new_node->data))))
        {
            temp = temp->next;
            (*count) += 2;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    return list;
}

// void showLL(node *list)
// {
//     node *temp = list;

//     while (temp != NULL)
//     {
//         printf("%0.2f->", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

node *delete_start(node *list, float *d)
{
    node *temp = list;
    list = list->next;

    *d = temp->data;
    free(temp);

    return list;
}

void bucket_sort(float *arr, int n, int *count)
{
    node *bins[n];

    for (int i = 0; i < n; i++)
        bins[i] = NULL;

    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        pos = floor(n * arr[i]);

        bins[pos] = LL_insert_sorted(bins[pos], arr[i], count);
        (*count)++;
    }

    pos = 0;
    float temp;

    for (int i = 0; i < n; i++)
    {
        while (bins[i] != NULL)
        {
            bins[i] = delete_start(bins[i], &temp);
            arr[pos] = temp;
            pos++;
        }
    }
}

// //assuming 1 is true, 0 is false
// int is_list_sorted(node *list)
// {
//     node *prev = list;
//     node *temp = list->next;

//     while (temp != NULL)
//     {
//         if (prev->data > temp->data)
//             return 0;

//         prev = temp;
//         temp = temp->next;
//     }

//     return 1;
// }

int is_array_sorted(float *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

void text_to_arr(float *arr, int n)
{

    FILE *fin = fopen("./normalized_normal_distribution.csv", "r");
    char a[6];
    fscanf(fin, "%s\n", a);
    float temp = 0;
    for (int i = 0; i < n; i++)
    {
        int skip_line = rand() % 10;

        for (int j = 0; j < skip_line; j++)
            fscanf(fin, "%f\n", &temp);

        fscanf(fin, "%f\n", &temp);
        arr[i] = temp;
    }

    fclose(fin);
}

void main()
{
    srand(time(0));

    int max_p = 19;
    int num_iter_power = 100;

    FILE *fout = fopen("bucket_normal_obs.csv", "w");

    fprintf(fout, "num_elements,avg_comparison,avg_time\n");

    int n = 2;
    for (int p = 0; p < max_p; p++)
    {
        long sum_count = 0;
        float sum_time = 0;

        for (int i = 0; i < num_iter_power; i++)
        {
            float a[n];

            text_to_arr(a, n);

            // for (int i = 0; i < n; i++)
            //     printf("%0.2f,", a[i]);
            // printf("\n");

            int count = 0;

            float start_time = clock();
            bucket_sort(a, n, &count);
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