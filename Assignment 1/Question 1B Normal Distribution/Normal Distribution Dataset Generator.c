//this will generate a data set of 200 numbers in range 0-100 distributed uniformly
#include <stdio.h>
#include <time.h>   //for random seed
#include <stdlib.h> //for rand() and srand()

const int NO_OF_ELEMENTS = 10e6;
const int MAX_VALUE = 100;
const int NO_OF_SUB_ELEMENTS = 10;

void main()
{
    srand(time(0));

    FILE *fout = fopen("./Assignment 1/Question 1B Normal Distribution/normal_distribution.csv", "w");

    for (int i = 0; i < NO_OF_ELEMENTS; i++)
    {
        int sum = 0;
        for (int j = 0; j < NO_OF_SUB_ELEMENTS; j++)
        {
            sum += rand() % (MAX_VALUE / NO_OF_SUB_ELEMENTS);
        }
        fprintf(fout, "%d\n", sum);
    }
    fclose(fout);
}
