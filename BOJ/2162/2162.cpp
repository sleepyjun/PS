// https://www.acmicpc.net/problem/2162
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ll = long long;
using pll = std::pair<ll, ll>;
const int INF = std::numeric_limits<int>::max();

std::vector<pll> u, v;
int p[3001];
int find(int x)
{
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b) return;
	p[a] += p[b];
	p[b] = a;
}

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(p, p+3001, -1);
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x1, y1; cin >> x1 >> y1;
		int x2, y2; cin >> x2 >> y2;
		u.push_back({x1,y1});
		v.push_back({x2,y2});
		if(u[i] > v[i]) std::swap(u[i], v[i]);
	}

	for(int i = 0; i < n; ++i)
	{
		const pll& a = u[i];
		const pll& b = v[i];
		for(int j = i+1; j < n; ++j)
		{
			const pll& c = u[j];
			const pll& d = v[j];

			int abc = ccw(a.first, a.second, b.first, b.second, c.first, c.second);
			int abd = ccw(a.first, a.second, b.first, b.second, d.first, d.second);
			int cda = ccw(c.first, c.second, d.first, d.second, a.first, a.second);
			int cdb = ccw(c.first, c.second, d.first, d.second, b.first, b.second);

			int ab = abc*abd;
			int cd = cda*cdb;
			if(ab == 0 && cd == 0)
			{
				if(c <= b && a <= d)
					merge(i,j);
			}
			else if(ab <= 0 && cd <= 0)
				merge(i,j);
		}
	}

	int cnt = 0;
	int max = -1;
	for(int i = 0; i < n; ++i)
	{
		if(p[i] < 0)
		{
			cnt++;
			max = std::max(max, p[i]*-1);
		}
	}
	cout << cnt << '\n';
	cout << max << '\n';
}//g++ -o a -std=c++17 *.cpp