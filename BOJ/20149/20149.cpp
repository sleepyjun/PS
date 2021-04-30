// https://www.acmicpc.net/problem/20149
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ll = long long;
using pll = std::pair<ll, ll>;
const int INF = std::numeric_limits<int>::max();

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
void intersection(const pll& a, const pll& b, const pll& c, const pll& d)
{
	double px = (a.first * b.second - a.second * b.first) * (c.first - d.first) - (a.first - b.first) * (c.first * d.second - c.second * d.first);
	double py = (a.first * b.second - a.second * b.first) * (c.second - d.second) - (a.second - b.second) * (c.first * d.second - c.second * d.first);
	double p = (a.first - b.first) * (c.second - d.second) - (a.second - b.second) * (c.first - d.first);

	if (p == 0)
	{
		if (b == c && a <= c) cout << b.first << " " << b.second << '\n';
		else if (a == d && c <= a) cout << a.first << " " << a.second << '\n';
	}
	else
	{
		double x = px / p;
		double y = py / p;

		cout << std::fixed;
		cout.precision(17);
		cout << x << " " << y;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	pll a,b,c,d;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	cin >> d.first >> d.second;

	if(a>b) std::swap(a,b);
	if(c>d) std::swap(c,d);

	int abc = ccw(a.first, a.second, b.first, b.second, c.first, c.second);
	int abd = ccw(a.first, a.second, b.first, b.second, d.first, d.second);
	int cda = ccw(c.first, c.second, d.first, d.second, a.first, a.second);
	int cdb = ccw(c.first, c.second, d.first, d.second, b.first, b.second);

	int ab = abc*abd;
	int cd = cda*cdb;

	if(ab == 0 && cd == 0)
	{
		if(c <= b && a <= d)
		{
			cout << 1 << '\n';
			intersection(a, b, c, d);
			return 0;
		}
	}
	else if(ab <= 0 && cd <= 0)
	{
		cout << 1 << '\n';
		intersection(a, b, c, d);
		return 0;
	}
	cout << 0;
	return 0;
}//g++ -o a -std=c++11 *.cpp