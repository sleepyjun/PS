#include<stdio.h>
#include<string.h>

int main()
{
	char temp[6];
	int N;
	int X;
	int arr[10001], a=0;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%s", temp);
		if (!strcmp(temp, "push"))
		{
			scanf("%d", &X);
			arr[a] = X; a++;
		}
		else if (!strcmp(temp, "pop"))
		{
			if (a > 0)
			{
				printf("%d\n", arr[--a]);
				arr[a] = NULL;
			}
			else
				printf("-1\n");						
		}
		else if (!strcmp(temp, "size"))
		{
			printf("%d\n", a);
		}
		else if (!strcmp(temp, "empty"))
		{
			if (a == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(temp, "top"))
		{
			if (a == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", arr[a-1]);
			}
		}
	}
}