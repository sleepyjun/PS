#include<stdio.h>

int main()
{
	int N;
	int i, tmp;
	int sum,ans;
	scanf("%d", &N);

	for (i = 1; i <= N; ++i)
	{
		tmp = i;
		sum = tmp;
		sum += tmp % 10;
		while (tmp /= 10)
		{
			sum += tmp % 10;
		}
		if (sum == N)
		{
			ans = i; break;
		}
		else
			ans = 0;
	}
	printf("%d", ans);
}