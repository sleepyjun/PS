// https://www.acmicpc.net/problem/11444
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const long long MOD = 1000000007;

void mulMatrix(long long dest[2][2], long long src[2][2])
{
	long long c[2][2] = {0,0,0,0};
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				c[i][j] = (c[i][j] + (dest[i][k]*src[k][j]))%MOD;
	std::copy(&c[0][0],&c[1][2],&dest[0][0]);
}
long long fastPowMatrix(long long exp)
{
	long long res[2][2] = {
		{1,0},
		{0,1}
	}, base[2][2] = {
		{1,1},
		{1,0}
	};

	while(exp)
	{
		if(exp&1)
			mulMatrix(res,base);
		mulMatrix(base,base);
		exp >>= 1;
	}
	return res[0][1];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long n; cin >> n;
	cout << fastPowMatrix(n) << '\n';
}//g++ -o a -std=c++11 *.cpp