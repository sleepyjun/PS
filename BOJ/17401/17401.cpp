// https://www.acmicpc.net/problem/17401
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const long long MOD = 1e9+7;
long long map[101][21][21];
long long res[21][21];
int t,n,d; 

void mulMatrix(int dest, int src)
{
	long long matrix[21][21];
	std::fill(&matrix[0][0], &matrix[20][21], 0);

	if(dest == -1)
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				for(int k = 1; k <= n; ++k)
					matrix[i][j] = (matrix[i][j] + (res[i][k]*map[src][k][j]))%MOD;
		std::copy(&matrix[0][0],&matrix[20][21],&res[0][0]);
	}
	else
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				for(int k = 1; k <= n; ++k)
					matrix[i][j] = (matrix[i][j] + (map[dest][i][k]*map[src][k][j]))%MOD;
		std::copy(&matrix[0][0],&matrix[20][21],&map[dest][0][0]);	
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t >> n >> d;
	for(int i = 1; i <= t; ++i)
	{
		int m; cin >> m;

		for(int j = 0; j < m; ++j)
		{
			int u,v,w; cin >> u >> v >> w;
			map[i][u][v] = w;
		}
	}
	for(int i = 0; i <= n; ++i)
		map[0][i][i] = 1;
	
	for(int i = 1; i <= t && i <= d; ++i)
	{
		mulMatrix(0,i);
	}

	if(t > d)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
				cout << map[0][i][j] << ' ';
			cout << '\n';
		}
	}
	else
	{
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j) res[i][j] = map[0][i][j];

		int exp = (d-t)/t;
		int remain = (d-t)%t;
		while(exp)
		{
			if(exp&1)
				mulMatrix(-1,0);
			mulMatrix(0,0);
			exp >>= 1;
		}

		for(int i = 1; i <= remain; ++i)
			mulMatrix(-1,i);
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
				cout << res[i][j] << ' ';
			cout << '\n';
		}
	}
}//g++ -o a -std=c++17 *.cpp