#include<stdio.h>

int main()
{
	int a[10] = { 0 }, cnt=0;
	int N;
	int i, j;

	scanf("%d", &N);

	while (N > 0)
	{
		a[N % 10]++;
		N /= 10;
	}

	for (i = 9; i >= 0; --i)
		for (j = 0; j < a[i]; ++j)
			printf("%d", i);
}