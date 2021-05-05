// https://www.acmicpc.net/problem/7869
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
const double PI = 3.141592653589793;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << std::fixed; cout.precision(3);

	double x1,y1,r1; cin >> x1 >> y1 >> r1;
	double x2,y2,r2; cin >> x2 >> y2 >> r2;

	double maxr = std::max(r1,r2);
	double minr = std::min(r1,r2);

	double d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
	if(d >= r1+r2)
	{
		cout << 0.0;
	}
	else if(maxr-minr < d && d < r1+r2)
	{
		double a = (r1*r1 - r2*r2 + d*d) / (2*d);
		double b = d-a;
		double h = sqrt(r1*r1 - a*a);

		double atheta = acos(a/r1);
		double btheta = acos(b/r2);

		double ans = r1*r1*atheta + r2*r2*btheta - d*h;

		cout << ans;
	}
	else if(d <= maxr-minr)
	{
		cout << minr*minr*PI;
	}
	cout << '\n';
	return 0;
}//g++ -o a -std=c++17 *.cpp