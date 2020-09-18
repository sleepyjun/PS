#include<stdio.h>

int main()
{
	int num;
	int i;
	int sum = 0;
	char arr[101] = { 0 };

	scanf("%d", &num);
	scanf("%s", arr);
	
	for (i = 0; i < num; ++i)
	{
		sum += (arr[i] - '0');
	}

	printf("%d", sum);

	return 0;
}