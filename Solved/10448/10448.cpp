#include<stdio.h>

int istri(int arr[],int N)
{
	int i, j, k;
	for (i = 1; i < 45; ++i)
		for (j = 1; j < 45; ++j)
			for (k = 1; k < 45; ++k)
				if (arr[i] + arr[k] + arr[j] == N)
					return 1;

	return 0;
}
int main()
{
	int T, N;
	int arr[46] = { 0, };
	int i;

	scanf("%d", &T);

	for (i = 1; i < 45; ++i)
		arr[i] = ((i)*(i + 1)) / 2;
	for (i = 0; i < T; ++i)
	{
		scanf("%d", &N);
		if (istri(arr, N))
			printf("1\n");
		else
			printf("0\n");
	}
}