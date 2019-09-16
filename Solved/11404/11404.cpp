#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > map;
const int limit = 100001;

void floyd(const int& n)
{
	for(int k = 1; k <=n; ++k)
		for(int i = 1; i <=n; ++i)
			for (int j = 1; j <= n; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (map[i][j] == limit) map[i][j] = 0;
}
int main()
{
	int n = 101, m = 101;
	int from, to, cost;

	scanf("%d %d", &n, &m);
	map = vector< vector<int> >(n+1, vector<int>(n+1, limit));

	for (int i = 1; i <= n; ++i) map[i][i] = 0;
	for (int j = 1; j <= m; ++j)
	{
		scanf("%d %d %d", &from, &to, &cost);
		map[from][to] = cost < map[from][to] ? cost : map[from][to];
	}
	floyd(n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}