// https://www.acmicpc.net/problem/11780
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = 999999999;

int dist[101][101];
int path[101][101];
std::vector<int> pathResult;
void find(int s, int e)
{
	if(path[s][e] != -1)
	{
		find(s, path[s][e]);
		pathResult.push_back(path[s][e]);
		find(path[s][e], e);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&dist[0][0], &dist[100][101], INF);
	std::fill(&path[0][0], &path[100][101], -1);
	int n, m; cin >> n >> m;
	for(int i = 0; i <= n; ++i) dist[i][i] = 0;
	for(int i = 0; i < m; ++i)
	{
		int a,b,w; cin >> a >> b >> w;
		dist[a][b] = std::min(dist[a][b], w);
	}
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				int maybe = dist[i][k]+dist[k][j];
				if(dist[i][j] > maybe)
				{
					dist[i][j] = maybe;
					path[i][j] = k;
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
		cout << '\n';
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			pathResult.clear();
			if(i == j || dist[i][j] == INF) cout << 0;
			else
			{
				pathResult.push_back(i);
				find(i,j);
				pathResult.push_back(j);
				cout << pathResult.size() << ' ';
				for(int p: pathResult) cout << p << ' ';
			}
			cout << '\n';
		}
	}
}//g++ -o a -std=c++11 *.cpp