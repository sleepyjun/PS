// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MOD = 1e6+3;
ull map[51][51];
ull res[51][51];

int n;
void run(ull dest[51][51], ull src[51][51])
{
	ull temp[51][51];
	std::fill(&temp[0][0], &temp[50][51], 0);

	for(int i = 0; i < n*5; ++i)
		for(int j = 0; j < n*5; ++j)
			for(int k = 0; k < n*5; ++k)
				temp[i][j] = (temp[i][j] + dest[i][k]*src[k][j])%MOD;
	std::copy(&temp[0][0], &temp[50][51], &dest[0][0]);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int s, e, t;
	cin >> n >> s >> e >> t;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char x; cin >> x;
			if(x > '1')
			{
				map[5*i][5*j+(x-'1')] = 1;
			}
			if(x == '1') map[5*i][5*j] = 1;
		}
		res[5*i][5*i] = 1;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 1; j < 5; ++j)
		{
			map[5*i+j][5*i+j-1] = 1;
		}
	}

	while(t)
	{
		if(t&1) run(res, map);
		run(map, map);
		t>>=1;
	}
	s--; e--;
	cout << res[5*s][5*e] << '\n';
}//g++ -o a -std=c++17 *.cpp