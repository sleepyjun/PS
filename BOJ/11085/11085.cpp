// https://www.acmicpc.net/problem/11085
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

int point[1000];
int find(int n)
{
	if(point[n] < 0) return n;
	return point[n] = find(point[n]);
}
void merge(int p, int c)
{
	p = find(p);
	c = find(c);
	if(p==c) return;
	point[p] += point[c];
	point[c] = p;
}
bool compare(std::tuple<int,int,int> a,
			std::tuple<int,int,int> b)
{
	return std::get<2>(a) > std::get<2>(b);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int p,w; cin >> p >> w;
	int c,v; cin >> c >> v;
	std::vector<std::tuple<int, int, int> > route;
	std::fill(point,point+p,-1);
	route.reserve(w);
	for(int i = 0; i < w; ++i)
	{
		int s,e,v; cin >> s >> e >> v;
		route.push_back(std::make_tuple(s,e,v));
	}
	std::sort(route.begin(), route.end(), compare);
	
	for(auto node:route)
	{
		int s = std::get<0>(node);
		int e = std::get<1>(node);
		merge(s,e);
		if(find(c) == find(v))
		{
			cout << std::get<2>(node) << '\n';
			break;
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;