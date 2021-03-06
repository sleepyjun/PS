#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

bool line[10001];

int main()
{
	int N;
	int x, y;
	int maxY = -1;
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x, &y);
		if (x > y) swap(x, y); //x must small
		maxY = max(maxY, y);

		for (; x < y; ++x)
			line[x] = true;
	}

	for (int i = 1; i <= maxY; ++i)
		if (line[i]) cnt++;
	printf("%d", cnt);
}