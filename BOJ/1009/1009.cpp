// https://www.acmicpc.net/problem/1009
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int solve(int a, int b)
{
	const int MOD = 10;
	int res = 1;
	while(b)
	{
		if(b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return res == 0 ? 10 : res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int a, b; cin >> a >> b;
		cout << solve(a,b) << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;