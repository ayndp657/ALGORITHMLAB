#include <iostream>
using namespace std;
#include <stdlib.h> //for qsort()

const int x = 1;
const int y = 0;
const int z = 9;

const int arr_size = 6;

typedef struct task
{
    int deadline;
    int penalty;
} task;

int generate_num(int a, int b)
{
    return 10 * a + b;
}

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

int main()
{
    task data[arr_size] = {{y + 1, generate_num(z, x) + 30},
                           {x + 2, generate_num(y, z) + 20},
                           {3, 50},
                           {2, 60},
                           {1, 25},
                           {4, 35}};

    qsort(data, arr_size, sizeof(task), comp_task);

    int max_deadline = -1;

    for (int i = 0; i < arr_size; i++)
        if (data[i].deadline > max_deadline)
            max_deadline = data[i].deadline;

    int N[max_deadline] = {0};
    bool included[arr_size] = {false};
    int penalty = 0;

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

    task backup[arr_size] = {{y + 1, generate_num(z, x) + 30},
                             {x + 2, generate_num(y, z) + 20},
                             {3, 50},
                             {2, 60},
                             {1, 25},
                             {4, 35}};

    cout << "Following Tasks Are Selected: ";

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            if (is_equal(backup[i], data[j]))
            {
                if (included[j])
                    cout << "T" << i + 1 << ", ";
            }
        }
    }

    cout << endl
         << "Penalty: " << penalty << endl;

    return 0;
}