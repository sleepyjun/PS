// https://www.acmicpc.net/problem/13141
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = 99999999;

int dist[201][201];
int map[201][201];


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&dist[0][0], &dist[200][201], INF);
	std::fill(&map[0][0], &map[200][201], INF);
	
	int n,m; cin >> n >> m;
	for(int i = 0; i <= n; ++i) dist[i][i] = 0;
	for(int i = 0; i < m; ++i)
	{
		int u, v, w; cin >> u >> v >> w;

		if(map[u][v] != INF) map[u][v] = std::max(map[u][v], w);
		else map[u][v] = w;
		dist[u][v] = std::min(dist[u][v], w);

		dist[v][u] = dist[u][v];
		map[v][u] = map[u][v];
	}

	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);


	double res = INF;
	for(int i = 1; i <= n; ++i)
	{
		double time = 0;
		for(int u = 1; u <= n; ++u)
		{
			for(int v = 1; v <= n; ++v)
			{
				if(map[u][v] == INF) continue;

				double len = map[u][v] - (std::abs(dist[i][u] - dist[i][v]));

				if(len >= 0)
				{
					double temp = len/2 + std::max(dist[i][u], dist[i][v]);
					time = std::max(time, temp);
				}
			}
		}

		res = std::min(res, time);
	}

	cout << std::fixed;
	cout.precision(1);

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp