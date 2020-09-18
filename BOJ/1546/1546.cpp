#include<stdio.h>

int Max(double arr[],int cnt)
{
	int max;
	int i;
	max = arr[0];
	for (i = 1; i < cnt; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}
int main()
{
	double arr[1001];
	int cnt, i, mx;
	double sum = 0;

	scanf("%d", &cnt);

	for (i = 0; i < cnt; ++i)
	{
		scanf("%lf", &arr[i]);
	}

	mx=Max(arr,cnt);

	for (i = 0; i < cnt; ++i)
	{
		sum+=arr[i]/mx*100;
	}

	printf("%.2lf", sum / cnt);

	return 0;
}