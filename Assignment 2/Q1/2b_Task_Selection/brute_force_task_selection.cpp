#include <iostream>
using namespace std;
#include <cmath>
#include <fstream>

void update_binary(bool *binary, u_long len)
{
    u_long iterator = len - 1;

    if (binary[iterator] == false)
    {
        binary[iterator] = true;
        return;
    }
    else
    {
        while (binary[iterator] != false && iterator != 0)
        {
            binary[iterator] = false;
            iterator--;
        }
        binary[iterator] = true;
    }
}

struct task
{
    u_long deadline;
    u_long penalty;
};

void update_penalty(bool *binary, task *tasks, const u_long &num_tasks, u_long &min_penalty)
{
    u_long max_deadline = 0;

    for (int i = 0; i < num_tasks; i++)
        if (tasks[i].deadline > max_deadline)
            max_deadline = tasks[i].deadline;

    u_long N[max_deadline] = {0};
    u_long penalty = 0;

    for (int i = 0; i < num_tasks; i++)
    {
        if (binary[i] == false)
            penalty += tasks[i].penalty;
        else
            for (int j = tasks[i].deadline - 1; j < max_deadline; j++)
                N[j]++;
    }

    for (int i = 0; i < max_deadline; i++)
        if (N[i] > i + 1)
            return;

    if (min_penalty > penalty)
        min_penalty = penalty;
}

const int max_n = 25;
const int num_iter_per_n = 1;

int main()
{
    ofstream fout("brute_force.csv", ios::out);
    fout << "n,avg_time_taken_ms" << endl;

    srand(time(0));
    u_long arr_size = 6;

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

            bool binary[arr_size] = {false};
            u_long min_penalty = __LONG_MAX__;

            float start_time = clock();
            for (int i = 0; i < pow(2, arr_size); i++)
            {
                update_penalty(binary, data, arr_size, min_penalty);
                update_binary(binary, arr_size);
            }
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