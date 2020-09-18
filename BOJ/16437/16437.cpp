// https://www.acmicpc.net/problem/16437
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

using data = std::tuple<char, int, int>;
using std::make_tuple;
std::vector<data> v[123457];
long long dfs(const data& curr)
{
	bool flag = true;
	int idx = std::get<2>(curr);
	long long res = 0;
	// cout << idx << '\n';
	for(auto node : v[idx])
	{
		int next = std::get<2>(node);
		
		res += dfs(node);
	}
	// if(flag)
	// {
		char type = std::get<0>(curr);
		int src = std::get<1>(curr);
		if(type == 'W') res -= src;
		else res += src;
		if(res <= 0) return 0;
		return res;
	// }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 2; i <= n; ++i)
	{
		char t; cin >> t;
		int a,p; cin >> a >> p;
		v[p].push_back(make_tuple(t,a,i));
	}
	cout << dfs(make_tuple('S',0,1)) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;