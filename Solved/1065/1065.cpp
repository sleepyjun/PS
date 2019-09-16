#include<stdio.h>

int hansu(int a)
{
	int i,cnt=0;
	int st, nd, rd;
	for (i = 1; i <= a; ++i)
	{
		if(i<100)
			++cnt;
		else if (i >= 100 && i < 1000)
		{
			st = i / 100;
			nd = (i / 10) % 10;
			rd = i % 10;

			if ((st+rd)/2.0==nd)
				cnt++;
		}

	}

	return cnt;
}
int main()
{
	int n,a;
	scanf("%d", &n);

	a=hansu(n);
	printf("%d", a);

	return 0;
}