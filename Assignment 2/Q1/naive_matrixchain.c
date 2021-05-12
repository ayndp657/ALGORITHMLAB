/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// place parenthesis at different places between first
	// and last matrix, recursively calculate count of
	// multiplications for each parenthesis placement and
	// return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver code
int main()
{
	for (int i = 0; i < 100; i++)
	{
		//srand(time(0));
		int a[6];
		for (int j = 0; j < 6; j++)
		{
			a[j] = rand() % 10;
		}
		printf("\nArray elements are : \n");
		for (int j = 0; j < 6; j++)
		{
			printf("%d , ", a[j]);
		}
		float start_time = clock();
		printf("\nMinimum number of multiplications is %d ",
		MatrixChainOrder(a, 1, 5));
		printf("\n");
		float end_time = clock();
		printf("Run %d: %0.4fms\n", i + 1, (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
	}
	getchar();
	return 0;
}