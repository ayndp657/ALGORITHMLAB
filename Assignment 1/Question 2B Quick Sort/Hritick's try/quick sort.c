#include<stdio.h>
#include<stdlib.h>
int n,i,j ;

 int main()
{
	printf("\nEnter the size:");
	scanf("%d",&n);
	int a[n];
	insert(a);
	print(a);
	return 0;
}
void insert(int a[])
{
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void print(int a[])
{
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
}

