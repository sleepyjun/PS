// https://www.acmicpc.net/problem/1774
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int p[1001];
int find(int a)
{
	if(p[a] < 0) return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b) return false;
	p[b] = a;
	return true;
}

struct edge {
	int u, v;
	double w;
	edge() {}
	edge(int _u, int _v, double _w): u(_u), v(_v), w(_w) {}
	bool operator <(const edge &E)
	{
		return w < E.w;
	}
};

double dist(const pii& a, const pii& b)
{
	long long dx = a.first - b.first;
	long long dy = a.second - b.second;
	return sqrt(dy*dy+dx*dx);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(p, p+1001, -1);
	std::vector<pii> map;
	std::vector<edge> info;
	int n,m; cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		map.push_back({x,y});
	}
	for(int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y;
		if(x > y) std::swap(x,y);
		merge(x-1,y-1);
	}
	for(int i = 0; i < map.size(); ++i)
	{
		for(int j = i+1; j < map.size(); ++j)
		{
			double w = dist(map[i], map[j]);
			info.push_back(edge(i,j,w));
		}
	}
	std::sort(info.begin(), info.end());

	double result = 0;
	for(const auto& e: info)
	{
		if(true == merge(e.u, e.v))
		{
			result += e.w;
			if(++m == n-1) break;
		}
	}
	cout << std::fixed;
	cout.precision(2);
	cout << result << '\n';
}//g++ -o a -std=c++11 *.cpp