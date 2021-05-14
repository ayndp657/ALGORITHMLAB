#include <iostream>
using namespace std;
#include <stdlib.h> //for qsort()
#include <fstream>

typedef struct task
{
    int deadline;
    int penalty;
} task;

int comp_task(const void *a, const void *b)
{
    return (((task *)b)->penalty) - (((task *)a)->penalty); //revese as we need descending
}

bool is_equal(const task &a, const task &b)
{
    if (a.deadline == b.deadline)
        if (a.penalty == b.penalty)
            return true;

    return false;
}

u_long greedy_task_selection(task *data, const u_long arr_size)
{
    qsort(data, arr_size, sizeof(task), comp_task);

    int max_deadline = -1;

    for (int i = 0; i < arr_size; i++)
        if (data[i].deadline > max_deadline)
            max_deadline = data[i].deadline;

    int N[max_deadline] = {0};
    bool included[arr_size] = {false};
    u_long penalty = 0;

    for (int i = 0; i < arr_size; i++)
    {
        bool independent = true;

        for (int j = data[i].deadline - 1; j < max_deadline; j++)
            if (N[j] + 1 > j + 1)
            {
                independent = false;
                penalty += data[i].penalty;
                break;
            }

        if (independent)
        {
            for (int j = data[i].deadline - 1; j < max_deadline; j++)
                N[j]++;

            included[i] = true;
        }
    }

    return penalty;
}

const int max_n = 50;
const int num_iter_per_n = 10;

int main()
{
    ofstream fout("greedy.csv", ios::out);
    fout << "n,avg_time_taken_ms" << endl;

    srand(time(0));

    for (int arr_size = 2; arr_size <= max_n; arr_size++)
    {
        float avg_time = 0;
        for (int i = 0; i < num_iter_per_n; i++)
        {
            task data[arr_size];

            for (int i = 0; i < arr_size; i++)
            {
                data[i].deadline = rand() % arr_size + 1;
                data[i].penalty = (rand() % arr_size + 1) * 10;
            }

            float start_time = clock();
            u_long penalty = greedy_task_selection(data, arr_size);
            float end_time = clock();
            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            cout << "size " << arr_size << " Time Taken: " << time_taken << "ms" << endl;
            avg_time += time_taken;
        }
        avg_time /= num_iter_per_n;
        fout << arr_size << "," << avg_time << endl;
    }

    fout.close();
    return 0;
}