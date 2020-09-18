#include<stdio.h>

int main()
{
	int stack[10001];
	char str[20002];
	int N, temp;
	int top = 0, flag = 0;
	int cnt = 0;
	int num = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		if (temp > N || stack[top] > temp)
		{
			flag = 1;
			break;
		}
		while (num <= temp)
		{
			stack[++top] = num++;
			str[cnt++] = '+';
		}
		top--;
		str[cnt++] = '-';
	}

	if (flag)
		puts("NO");
	else
		for (int i = 0; i < cnt; ++i)
			printf("%c\n", str[i]);
}