#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, temp;
	int *arr;
	int i, j,k;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	for (i = 1; i < N; ++i)
	{
		k = arr[i];
		for (j = i - 1; j >= 0 && k < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = k;
	}

	for (i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
}