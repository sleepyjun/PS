// https://www.acmicpc.net/problem/12852
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int dp[1000001];
int path[1000001];

void print(int x)
{
	cout << x << ' ';
	if(x == 1) return;
	print(path[x]);
}
int func(int x)
{
	int& ret = dp[x];
	if(ret != -1) return ret;
	if(x==1) return 0;
	ret = func(x-1)+1;
	path[x] = x-1;
	if(x%2 == 0)
	{
		int temp = func(x/2)+1;
		if(temp < ret)
		{
			ret = temp;
			path[x] = x/2;
		}
	}
	if(x%3 == 0)
	{
		int temp = func(x/3)+1;
		if(temp < ret)
		{
			ret = temp;
			path[x] = x/3;
		}
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::fill(dp,dp+n+1,-1);
	std::fill(path,path+n+1,-1);
	cout << func(n) << '\n';
	print(n);
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;