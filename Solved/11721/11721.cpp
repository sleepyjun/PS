#include<stdio.h>
#include<string.h>
int main()
{
	char arr[121];
	char temp;
	int i,a=0;

	scanf("%s", arr);

	a = strlen(arr);
	
	for (i = 0; i < a; ++i)
	{
		printf("%c", arr[i]);
		if (i % 10==9)
		{
			printf("\n");
		}
	}

	return 0;
}
