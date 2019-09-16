#include<stdio.h>
int main()
{
	char c;
	while (1)
	{
		c = getchar();
		putchar(c);
		if (c == EOF)
			break;
	}
}