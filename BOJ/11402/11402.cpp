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

int c[2001][2001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long n, k, m; cin >> n >> k >> m;

	for(int i = 0; i <= m; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			if(j == 0 || j == i)
			{
				c[i][j] = 1;
				continue;
			}
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % m;
		}
	}

	int res = 1;
	while(n || k)
	{
		res = (res * c[n%m][k%m])%m;
		n/=m;
		k/=m;
	}
	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp