#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

char star[3072][6143];

void staring(int n, int x, int y);
int main()
{
	int n;
	memset(star, ' ', sizeof(star));
	scanf("%d", &n);
	int weight = n * 2 - 1;
	staring(n, n - 1, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < weight; ++j)
		{
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
}

void staring(int n, int x, int y)
{
	if (n == 3)
	{
		star[y][x] =  '*';										//  *
		star[y + 1][x - 1] = star[y + 1][x + 1] = '*';			// * *
		star[y + 2][x - 2] = star[y + 2][x - 1] = star[y + 2][x]//*****
			= star[y + 2][x + 1] = star[y + 2][x + 2] = '*';
	}
	else
	{
		staring(n / 2, x, y);
		staring(n / 2, x + (n / 2), y + (n / 2));
		staring(n / 2, x - (n / 2), y + (n / 2));
	}
}