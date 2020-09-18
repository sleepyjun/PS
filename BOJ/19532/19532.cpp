// https://www.acmicpc.net/problem/19532
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int a,b,c; //ax+by=c
	int d,e,f; //dx+ey=f
	cin >> a >> b >> c >> d >> e >> f;
	
	int det = a*e-b*d;
	int x = (e*c-f*b)/det;
	int y = (-d*c+a*f)/det;
	
	cout << x << ' ' << y << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;