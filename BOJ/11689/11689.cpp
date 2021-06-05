// https://www.acmicpc.net/problem/11689
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull n; cin >> n;
	ull res = n;
	for(ull i = 2; i*i <= n; ++i)
	{
		if(n%i == 0)
		{
			res /= i;
			res *= (i-1);
		}
		while(n%i == 0) n /= i;
	}
	if(n != 1)
	{
		res /= n;
		res *= (n-1);
	}
	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp