#include<stdio.h>
#include<stdlib.h>

void quicksort(int arr[],int start,int end);

int main()
{
	int N;
	int *arr;
	
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	quicksort(arr,0,N-1);

	for (int i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
}

void quicksort(int arr[],int start,int end)
{
	int left;
	int right;
	int pivot;
	int temp;
	if ((end - start) > 1)
	{
		left = start;
		right = end;
		pivot = arr[(end + start) / 2];

		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
		quicksort(arr, start, right);
		quicksort(arr, left, end);
	}
	//되긴 되는데 시간초과 ㅎㅎ;
}