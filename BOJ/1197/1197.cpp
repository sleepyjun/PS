// https://www.acmicpc.net/problem/1197
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

int parent[10001];

int find(int n)
{
	if(parent[n] == -1) return n;
	return find(parent[n]);
}
bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return false;
	parent[y] = x;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::vector<std::tuple<int, int, int> > t;
	int v,e; cin >> v >> e;
	for(int i = 0; i < e; ++i)
	{
		int x,y,w; cin >> x >> y >> w;
		t.push_back(std::make_tuple(w,x,y));
	}
	std::sort(t.begin(), t.end());
	std::fill(parent, parent+10001, -1);

	long long res = 0;
	for(const auto &n : t)
	{
		int w,x,y;
		std::tie(w,x,y) = n;
		if(merge(x,y) == true)
			res += (long long)w;
	}
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp