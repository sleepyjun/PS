// https://www.acmicpc.net/problem/1086
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n, k;
int mods[15], modsof10[15];
long long dp[1<<15][100];
std::vector<std::string> arr;

//a bigger than b
long long gcd(long long a, long long b)
{
	while(b != 0)
	{
		long long n = a%b;
		a = b;
		b = n;
	}
	return a;
}
int mod(const std::string &num)
{
	int res = 0;
	for(char n: num)
		res = (res*10 + (int)(n-'0')) % k;
		
	return res;
}
int modof10(int exp)
{
	int res = 1;
	for(int i = 1; i <= exp; ++i)
		res = (res*10)%k;
	return res;
}
long long func(int set, int mod)
{
	if(set == (1<<n)-1) return (mod == 0);

	long long &ret = dp[set][mod];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < n; ++i)
	{
		int bit = (1<<i);
		if(set&bit) continue;
	
		ret += func(set|bit, (mod*modsof10[i]+mods[i])%k);
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n; arr.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> k;

	for(int i = 0; i < n; ++i)
	{
		mods[i] = mod(arr[i]);
		modsof10[i] = modof10(arr[i].length());
	}
	std::fill(&dp[0][0], &dp[(1<<15)-1][100], -1);

	long long div = func(0,0);
	
	if(div == 0) cout << "0/1";
	else
	{
		long long all = 1; for(int i = 1; i <= n; ++i) all *= i;
		long long x = gcd(all, div);

		cout << div/x << '/' << all/x;
	}
	cout << '\n';
}//g++ -o a -std=c++11 *.cpp