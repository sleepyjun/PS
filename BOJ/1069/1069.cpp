// https://www.acmicpc.net/problem/1069
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

double dist(int y1, int x1, int y2=0, int x2=0)
{
	int ydist = (y1-y2)*(y1-y2);
	int xdist = (x1-x2)*(x1-x2);

	return sqrt(ydist+xdist);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << std::fixed;
	cout.precision(14);

	int x,y,d,t; cin >> x >> y >> d >> t;
	double l = dist(y,x);

	if(l >= d)
	{
		int jumpCnt = l/d;
		cout << std::min(l, std::min((double)(jumpCnt+1)*t, jumpCnt*t + l - jumpCnt*d));
	}
	else
	{
		cout << std::min(l, std::min(t+d-l, (double)t*2)) << '\n';
	}
}//g++ -o a -std=c++17 *.cpp