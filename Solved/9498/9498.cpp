#include<stdio.h>

int main()
{
	int num;
	char s;

	scanf("%d", &num);

	if (num <= 100 && num >= 90)
	{
		s = 'A';
	}
	else if (num<90 && num >= 80)
	{
		s = 'B';
	}
	else if (num<80 && num >= 70)
	{
		s = 'C';
	}
	else if (num<70 && num >= 60)
	{
		s = 'D';
	}
	else
	{
		s = 'F';
	}
	printf("%c", s);

	return 0;
}