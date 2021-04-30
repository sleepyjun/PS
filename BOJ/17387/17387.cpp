// https://www.acmicpc.net/problem/17386
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ll = long long;
using pii = std::pair<int, int>;
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

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int ax, ay; cin >> ax >> ay;
	int bx, by; cin >> bx >> by;
	int cx, cy; cin >> cx >> cy;
	int dx, dy; cin >> dx >> dy;

	int abc = ccw(ax, ay, bx, by, cx, cy);
	int abd = ccw(ax, ay, bx, by, dx, dy);
	int cda = ccw(cx, cy, dx, dy, ax, ay);
	int cdb = ccw(cx, cy, dx, dy, bx, by);

	if(abc == 0)
	{
		int minX = std::min(ax, bx), maxX = std::max(ax, bx);
		int minY = std::min(ay, by), maxY = std::max(ay, by);

		if(minX <= cx && cx <= maxX && minY <= cy && cy <= maxY)
			cout << 1;
		else cout << 0;
	}
	else if(abd == 0)
	{
		int minX = std::min(ax, bx), maxX = std::max(ax, bx);
		int minY = std::min(ay, by), maxY = std::max(ay, by);

		if(minX <= dx && dx <= maxX && minY <= dy && dy <= maxY)
			cout << 1;
		else cout << 0;
	}
	else if(cda == 0)
	{
		int minX = std::min(cx, dx), maxX = std::max(cx, dx);
		int minY = std::min(cy, dy), maxY = std::max(cy, dy);

		if(minX <= ax && ax <= maxX && minY <= ay && ay <= maxY)
			cout << 1;
		else cout << 0;
	}
	else if(cdb == 0)
	{
		int minX = std::min(cx, dx), maxX = std::max(cx, dx);
		int minY = std::min(cy, dy), maxY = std::max(cy, dy);

		if(minX <= bx && bx <= maxX && minY <= by && by <= maxY)
			cout << 1;
		else cout << 0;
	}
	else if((abc != abd) && (cda != cdb)) cout << 1;
	else cout << 0;
	cout << '\n';
}//g++ -o a -std=c++11 *.cpp