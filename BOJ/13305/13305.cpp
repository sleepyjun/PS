// https://www.acmicpc.net/problem/13305
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
	
	int n; cin >> n;
	std::vector<int> road(n-1);
	for(int i = 0; i < n-1; ++i)
		cin >> road[i];
	ull res = 0;
	ull min = INF;
	for(int i = 0; i < n; ++i)
	{
		ull x; cin >> x;
		if(i==n-1) break;
		min = std::min(min, x);
		res += min*road[i];
	}
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp