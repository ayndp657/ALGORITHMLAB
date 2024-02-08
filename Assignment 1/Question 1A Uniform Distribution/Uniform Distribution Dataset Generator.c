//this will generate a data set of 200 numbers in range 0-100 distributed uniformly 
#include <stdio.h>
#include <time.h>   //for random seed
#include <stdlib.h> //for rand() and srand()

const int NO_OF_ELEMENTS = 10e6;
const int MAX_VALUE = 100;

void main()
{
    srand(time(0));

    FILE *fout = fopen("./Assignment 1/Question 1A Uniform Distribution/uniformdistribution.csv", "w");

    for (int i = 0; i < NO_OF_ELEMENTS; i++)
    {
        fprintf(fout, "%d\n", rand() % MAX_VALUE);
    }
    fclose(fout);
}
