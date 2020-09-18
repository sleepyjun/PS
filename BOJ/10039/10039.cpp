#include<stdio.h>

int main()
{
	int arr[5];
	int sum = 0;
	int i;

	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &arr[i]);
		if (arr[i] < 40)
			arr[i] = 40;

		sum += arr[i];
	}

	printf("%d", sum / 5);

	return 0;
}