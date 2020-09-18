// https://www.acmicpc.net/problem/17435
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int table[200001][19]; 
/*
[i][j];
i번째 정점에서 2^j번 이동했을 경우의 값
*/

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int m; cin >> m;
	for(int i = 1; i <= m; ++i)
		cin >> table[i][0];
	for(int p = 1; p < 19; ++p)
	{
		for(int i = 1; i <= m; ++i)
		{
			table[i][p] = table[table[i][p-1]][p-1];
		}
	}
	int q; cin >> q;
	while(q--)
	{
		int n, x; cin >> n >> x;
		for(int j = 18; j >= 0; --j)
		{
			if(n >= (1<<j))
			{
				n -= (1<<j);
				x = table[x][j];
			}
		}
		cout << x << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;