// https://www.acmicpc.net/problem/4195
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int p[200001];
int parent(int a)
{
	if(p[a] < 0) return a;
	return p[a] = parent(p[a]);
}
void merge(int a, int b)
{
	a = parent(a);
	b = parent(b);

	if(a == b)
	{
		cout << abs(p[a]) << '\n';
		return;
	}
	p[a] += p[b];
	p[b] = a;
	cout << abs(p[a]) << '\n';
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int idx = 1;
		int f; cin >> f;
		std::map<std::string, int> m;
		std::fill(p, p+200001,-1);
		for(int i = 0; i < f; ++i)
		{
			std::string a,b;
			cin >> a >> b;
			if(m[a] == 0) m[a] = idx++;
			if(m[b] == 0) m[b] = idx++;
			merge(m[a], m[b]);
		}
	}
}//g++ -o a -std=c++11 *.cpp