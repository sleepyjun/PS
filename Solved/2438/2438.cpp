#include<stdio.h>

int main()
{
	int num, i, j;

	scanf("%d", &num);

	for (i = 0; i < num; ++i)
	{
		for (j = num-1; j > i; --j)
		{
			printf(" ");
		}
		for (j = 0; j <= i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}