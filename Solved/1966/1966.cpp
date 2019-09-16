#include<stdio.h>

#define MAX 300
int arr[MAX];
int isit[MAX];
int total;//array last index

void move(int i)
{
	for (i; i <= total; ++i)
	{
		arr[i] = arr[i+1];
		isit[i] = isit[i+1];
	}
	arr[total + 1] = 0;
	isit[total + 1] = 0;
}
void sol()
{
	int i = 0 , j;
	int flag;
	while(1)
	{
		flag = 1;
		for (j = i + 1; j <= total; ++j)
		{
			if (arr[i] < arr[j])
			{
				flag = 0;
				arr[total + 1] = arr[i];
				isit[total + 1] = isit[i];
				move(i);
			}
		}
		if (flag == 1)
		{
			i++;
		}
		if (i == total)
			break;
	}
}
int main()
{
	int T, N, M;
	int i, j;
	
	scanf("%d", &T);
	for (i = 0; i < T; ++i)
	{
		scanf("%d %d", &N, &M);
		total = N - 1;
		for (j = 0; j < N; ++j)
		{
			scanf("%d", &arr[j]);
			isit[j] = 0;
		}
		isit[M] = 1;
		if(total)
			sol();
		for (j = 0; j < N; ++j)
		{
			if (isit[j])
			{
				printf("%d\n", j + 1);
				break;
			}
		}
	}
	
}