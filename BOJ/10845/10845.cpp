#include<stdio.h>
#include<string.h>

#define MAX 10001

int arr[MAX]; // arr[0]은 사용하지않음
int size = 0;

void move(int arr[])
{
	for (int i = 1; i < size; ++i)
	{
		arr[i] = arr[i+1];
	}
}
int main()
{
	char str[6];
	// size가 0 이면 빈 것
	int temp;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%s", str);
		if (!strcmp(str, "push"))
		{
			scanf(" %d", &temp);
			++size;
			arr[size] = temp;
		}
		else if (!strcmp(str, "pop"))
		{
			if (size == 0)
				puts("-1");
			else
			{
				printf("%d\n", arr[1]);
				move(arr);
				size--;
			}
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", size);
		}
		else if (!strcmp(str, "empty"))
		{
			if (size)
				puts("0");
			else
				puts("1");
		}
		else if (!strcmp(str, "front"))
		{
			if (size)
				printf("%d\n", arr[1]);
			else
				puts("-1");
		}
		else if (!strcmp(str, "back"))
		{
			if (size)
				printf("%d\n", arr[size]);
			else
				puts("-1");
		}
	}
}