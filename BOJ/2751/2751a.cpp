#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void*b)
{
	int * x = (int *)a;
	int * y = (int *)b;

	return *x - *y;
}
int main()
{
	int N;
	int *arr;
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
}