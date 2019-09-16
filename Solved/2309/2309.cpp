#include<stdio.h>

int main()
{
	int arr[9];
	int i, j,sum = 0;
	int a, b;
	for (i = 0; i < 9; ++i)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for(i=0;i<9;++i)
		for(j=1;j<9-i;++j)
			if (arr[j-1] > arr[j])
			{
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}

	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j)
			if (sum - arr[i] - arr[j] == 100)
			{
				a=i; b=j; break;
			}
	for (i = 0; i < 9; ++i)
	{
		if (i == a || i == b)
			continue;
		else
			printf("%d\n", arr[i]);
	}
}