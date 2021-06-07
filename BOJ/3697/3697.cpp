// https://www.acmicpc.net/problem/3679
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <stack>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct Point {
	int x, y;
	int p, q;
	int idx;
	Point(): x(0), y(0), p(1), q(0) {}
	Point(int _x, int _y): x(_x), y(_y), p(1), q(0) {}
	
	bool operator <(const Point& O)
	{
		if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
		if(y != O.y) return y < O.y;
		return x < O.x;
	}
};

long long ccw(const Point& A, const Point& B, const Point& C){
    return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	Point p[2001];

	while(t--)
	{
		int n; cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int x,y; cin >> x >> y;
			p[i] = Point(x,y);
			p[i].idx = i;
		}
		std::sort(p,p+n);

		for(int i = 1; i < n; ++i)
		{
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		std::sort(p+1, p+n);

		int flag = n;
		for(int i = n-1; i >= 0; --i)
		{
			if(p[i].p * p[i-1].q != p[i].q * p[i-1].p)
			{
				flag = i-1;
				break;
			}
		}

		for(int i = 0; i <= flag; ++i)
			cout << p[i].idx << ' ';
		for(int i = n-1; i > flag; --i)
			cout << p[i].idx << ' ';
		cout << '\n';
	}
}//g++ -o a -std=c++17 *.cpp