#include<stdio.h>

int main()
{
	int C,i,j,n,cnt;
	int arr[1001][100];
	double ar[1001][2] = { 0 };
	double fact[1001];

	scanf("%d", &C);
	for (i = 0; i < C; ++i)
	{
		scanf("%d", &n);
		ar[i][0] = n;
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &arr[i][j]);
			ar[i][1] += arr[i][j];
		}
	}
	for (i = 0; i < C; ++i)
	{
		cnt = 0;
		fact[i] = (ar[i][1] / ar[i][0]);
		for (j = 0; j < ar[i][0]; ++j)
		{
			if (fact[i] < arr[i][j])
				++cnt;
		}
		printf("%.3f%%\n", (cnt/ar[i][0])*100);
	}
	return 0;

}