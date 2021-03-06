#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int temp[1001][1001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			if (j == 0 || i == j) temp[i][j] = 1;
			else
			{
				temp[i][j] = (temp[i - 1][j - 1] + temp[i - 1][j]) % 10007;
			}

	printf("%d", temp[n][k]);
}