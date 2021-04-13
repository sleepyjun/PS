// https://www.acmicpc.net/problem/13977
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const ull MOD = 1e9+7;
ull fac[4000001];
ull pow(ull n, ull k)
{
	ull res = 1;
	while(k)
	{
		if(k&1) res = (res*n)%MOD;
		k >>= 1;
		n = (n*n)%MOD;
	}
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	fac[1] = 1;
	for(int i = 2; i <= 4000000; ++i)
		fac[i] = (fac[i-1]*i)%MOD;
	
	while(t--)
	{
		int n,r; cin >> n >> r;
		if(n==r || r==0)
		{
			cout << 1 << '\n';
			continue;
		}
		r = ((n-r) < r) ? (n-r) : r;
		ull ans = fac[n];
		ull temp = (pow(fac[n-r],MOD-2)%MOD * pow(fac[r], MOD-2)%MOD) % MOD;
		ans = (ans * temp) % MOD;
		cout << ans << '\n';
	}
}//g++ -o a -std=c++11 *.cpp