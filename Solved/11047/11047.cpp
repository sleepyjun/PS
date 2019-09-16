#include<stdio.h>

int arr[10];
int N, K;
int ans()
{
	int total = 0;
	int i = 0;
	for (i = N - 1; i >= 0; --i)
		if (K / arr[i])
		{
			total += (K / arr[i]);
			K = (K%arr[i]);
		}
	return total;
}
int main()
{
	int i,sum;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	sum = ans();
	printf("%d", sum);
}