#include<stdio.h>

int main()
{

	int i,month,days,tmp;
	int mon[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char *day[8] = { {"SUN"}, {"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"} };

	scanf("%d %d", &month, &days);

	for (i = 0; i < month-1; ++i)
	{
		days += mon[i];
		
	}
	tmp = days % 7;
	printf("%s", day[tmp]);
	
	return 0;	
}