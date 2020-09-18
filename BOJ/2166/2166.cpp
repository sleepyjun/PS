// https://www.acmicpc.net/problem/2166
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

using pdd = std::pair<double, double>;

double ccw (double x1, double y1, double x2, double y2, double x3, double y3) {
	double a = x1 * y2 + x2 * y3 + x3 * y1;
	double b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<pdd> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	
	double sum = 0;
	for(int i = 1; i < n-1; ++i)
	{
		sum += ccw(v[0].first, v[0].second,
				  v[i].first, v[i].second,
				  v[i+1].first, v[i+1].second) / 2.0;
	}
	cout << std::fixed; cout.precision(1);
	cout << (sum < 0 ? sum*-1.0 : sum) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;