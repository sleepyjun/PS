#include<stdio.h>

int ans(int L, int P, int V)
{
	int tot = 0;
	while (V > 0)
	{
		tot += L;
		V -= P;
		if ((V>0)&&(V <= L))
		{
			tot += V;
			break;
		}
	}
	return tot;
}
int main()
{
	int L, P, V;
	int sum,i=1;
	while (1)
	{
		sum = 0;
		scanf("%d %d %d", &L, &P, &V);
		if ((!L && !P) && !V)
			break;
		sum = ans(L, P, V);
		printf("Case %d: %d\n", i++, sum);
	}
}