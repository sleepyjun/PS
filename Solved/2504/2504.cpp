#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//() = 2
	//[] = 3
	char str[31];
	char *stack;
	int N;
	int top = 0;
	int mul = 1;
	int flag = 0;
	int sum = 0;
	int itis = 1;
	scanf("%s", str);
	N = strlen(str);
	stack = (char*)malloc(N);

	for (int i = 0; i < N; ++i)
	{
		if (str[i] == '(')
		{
			mul *= 2;
			stack[top++] = '(';
			flag = 1;
		}
		else if (str[i] == '[')
		{
			mul *= 3;
			stack[top++] = '[';
			flag = 1;
		}
		else
		{
			if (str[i] == ')')
			{
				if (stack[top-1] != '(')
				{
					itis = 0; break;
				}
				if (flag)
					sum += mul;
				flag = 0;
				mul /= 2;
				top--;
			}
			else if (str[i] == ']')
			{
				if (stack[top - 1] != '[')
				{
					itis = 0; break;
				}
				if (flag)
					sum += mul;
				flag = 0;
				mul /= 3;
				top--;
			}
		}
	}
	if (top != 0 || itis == 0)
		printf("0");
	else
		printf("%d", sum);
}