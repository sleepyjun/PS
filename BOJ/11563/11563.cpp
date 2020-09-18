// https://www.acmicpc.net/problem/11563
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const long double INF = std::numeric_limits<long double>::max();

using line = std::tuple<long double, long double, long double, long double>;

long double distance(long double x1, long double y1,
			   long double x2, long double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
long double judge (long double x1, long double y1, long double x2, long double y2, long double x3, long double y3) {
	//A,B,X
	//1 AB X
	long double ab = (x2-x1)*(x3-x1) + (y2-y1)*(y3-y1);
	//1 BA X
	long double ba = (x1-x2)*(x3-x2) + (y1-y2)*(y3-y2);
	
	return (ab*ba >= 0);
}
long double vertical(long double x1, long double y1,
			   long double x2, long double y2,
			   long double a, long double b) //A,B,X
{
	if(judge(x1,y1,x2,y2,a,b) == false) return INF;
	long double p = a*y1 + x1*y2 + x2*b;
	long double m = b*x1 + y1*x2 + y2*a;
	if(p < m) std::swap(p,m);
	return (p-m)/distance(x1,y1,x2,y2);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << std::fixed; cout.precision(16);
	int n,m; cin >> n >> m;
	std::vector<line> Y(n), K(m);
	for(int i = 0; i < n; ++i)
	{
		long double x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
		Y[i] = std::make_tuple(x1,y1,x2,y2);
	}
	for(int i = 0; i < m; ++i)
	{
		long double x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
		K[i] = std::make_tuple(x1,y1,x2,y2);
	}
	
	long double res = INF;
	for(auto yLine : Y) //this is A B
	{
		long double x1,y1,x2,y2;
		std::tie(x1,y1,x2,y2) = yLine;
		for(auto kLine : K) //this is C D
		{
			long double x3,y3,x4,y4;
			std::tie(x3,y3,x4,y4) = kLine;
			
			//1 A-C B-C
			res = std::min(res, std::min(distance(x1,y1,x3,y3),
										distance(x2,y2,x3,y3)));
			//2 A-D B-D
			res = std::min(res, std::min(distance(x1,y1,x4,y4),
										distance(x2,y2,x4,y4)));
			//3 ABㅗC ABㅗD
			res = std::min(res, std::min(vertical(x1,y1,x2,y2,x3,y3),
										vertical(x1,y1,x2,y2,x4,y4)));
			
			//4 CDㅗA CDㅗB
			res = std::min(res, std::min(vertical(x3,y3,x4,y4,x1,y1),
										vertical(x3,y3,x4,y4,x2,y2)));
		}
	}
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;