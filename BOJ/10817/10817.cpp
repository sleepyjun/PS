#include<stdio.h.>

int main()
{
	int a, b, c;
	int temp;

	scanf("%d %d %d", &a, &b, &c);

	if (a > b)
	{
		if (b > c)
		{
			temp = b;
		}
		else//b<c
		{
			temp = c;
			if (a < c)
			{
				temp = a;
			}
		}
	}
	else//a<=b
	{
		if (a > c)
		{
			temp = a;
		}
		else//a<c
		{
			temp = c;
			if (c >= b)
				temp = b;
		}
	}

	printf("%d", temp);

	return 0;
}