// https://www.acmicpc.net/problem/16565
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MOD = 10007;
int comb[53][53];
int comb2[53][53];

void init()
{
	comb[0][0] = 1;
	for(int n = 1; n <= 52; ++n)
		for(int k = 0; k <= n; ++k)
			if(k == 0 || k == n) comb[n][k] = 1;
			else comb[n][k] = (comb[n-1][k-1] + comb[n-1][k])%MOD;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	init();
	int n; cin >> n;
	int res = 0;
	for(int i = 1; i <= 13; ++i)
	{
		int other = n-i*4;
		if(other < 0) break;
		res = (res + (i%2 ? 1 : -1)*comb[13][i]*comb[52-i*4][other])%MOD;
	}
	if(res < 0) res += MOD;
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp