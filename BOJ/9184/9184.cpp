// https://www.acmicpc.net/problem/9184
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int dp[51][51][51];
int w(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	int &ret = dp[a][b][c];
	if(ret != -1) return ret;
	if(a > 20 || b > 20 || c > 20) return ret = w(20, 20, 20);
	if(a < b && b < c) 
		return ret = (w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c));
	else 
		return ret = (w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1));
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		int a, b, c; cin >> a >> b >> c;
		if(a==-1&&b==-1&&c==-1) return 0;
		std::fill(&dp[0][0][0], &dp[50][50][51], -1);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << '\n';
	}
}//g++ -o a -std=c++11 *.cpp