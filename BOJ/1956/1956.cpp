#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int adj[401][401];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int v,e;
	cin >> v >> e;
	
	std::fill(&adj[0][0], &adj[v][v], INF);
	for(int i = 1; i <= v; ++i) adj[i][i] = 0;
	for(int i = 0; i < e; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		adj[a][b]=c;
	}

	for(int k = 1; k <= v; ++k)
	{
		for(int i = 1; i <= v; ++i)
		{
			for(int j = 1; j <= v; ++j)
			{
				if(adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	
	int res = INF;
	
	for(int i = 1; i <= v; ++i)
	{
		for(int j = 1; j <= v; ++j)
		{
			if(i==j)continue;
			res = std::min(res, adj[i][j]+adj[j][i]);
		}
	}
	cout << (res == INF ? -1 : res) << '\n';
}