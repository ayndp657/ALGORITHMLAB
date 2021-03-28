#include <stdio.h>

const int NO_OF_LINES = 10e6;
const int MAX_VALUE = 100;

int main()
{
    FILE *fin = fopen("./normal_distribution.csv", "r");

    FILE *fout = fopen("./normalized_normal_distribution.csv", "w");

    int temp;
    long long i = 0;

    while (!feof(fin))
    {
        i++;
        fscanf(fin, "%d\n", &temp);
        fprintf(fout, "%f\n", ((float)temp) / MAX_VALUE);
        printf("Uniform %f %% done\r", ((float)i) / NO_OF_LINES * 100);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}