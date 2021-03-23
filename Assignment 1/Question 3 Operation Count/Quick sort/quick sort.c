#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
int n,i,j ;
int insert(int a[],int z,int n)
{
	FILE *fptr;
	if((fptr=fopen("demo.txt","r"))==NULL)
	{
		printf("\nError! opening file.");
		exit(1);
	}
	for(i=z;i<n;i++)
	{
		fscanf(fptr,"%d",&a[i]);
}
fclose(fptr);
		
}
void print(int a[],int z,int n)
{
	for(i=z;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
}
int Quicksort(int a[],int p,int r)
{
	int q;
	if (p<r)
	{
		q=partition(a,p,r);
		Quicksort(a,p,q-1);
		Quicksort(a,q+1,r);
	
	}
}
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
 
int partition (int a[], int start, int end) 
{ 
    int pivot = a[end]; 
    int i = (start - 1); 
 
    for ( j = start; j <= end - 1; j++) 
    { 
       
        if (a[j] < pivot) 
        { 
            i++; 
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[end]); 
    return (i + 1); 
} 

 int main()
{
	int lower,upper,lower1,upper1;
	printf("\nEnter the lower bound to start the dataset value:");
	scanf("%d",&lower);
	printf("\nEnter the upper bound to start the dataset value:");
	scanf("%d",&upper);
	printf("\nEnter the lower bound to end the dataset value:");
	scanf("%d",&lower1  );
	printf("\nEnter the lower bound to end the dataset value:");
	scanf("%d",&upper1);
	srand(time(0));
	int z=(rand() %(upper - lower + 1)) + lower;
	int n=(rand() %(upper1 - lower1 + 1)) + lower;
    int diff=n-z;
    printf("\n %d %d ", n,z);
    printf("\n %d",diff);
	int a[diff];
	insert(a,z,n);
	print(a,z,n);
	Quicksort(a,z,n);
	printf("\nthe sorted array:");
	print(a,z,n);
	printf("\nthe number of comparison in the dataset:");
	unsigned int b = diff; 
    printf("%d", (int)b*(log(b)/log(2)));
    FILE *kptr;
    kptr=fopen("result.txt","a");
    if(kptr == NULL)
    {
    	printf("ERROR!");
    	
	}
	fprintf(kptr,"\nthe total number of elements:%d",diff);
	fprintf(kptr,"\nthe total comparison:%d",(int)b*(log(b)/log(2)));
	fclose(kptr);
	return 0;
}



