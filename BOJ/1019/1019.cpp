// https://www.acmicpc.net/problem/1019
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
int res[10];

void count(int n, int t)
{
	while(n>0)
	{
		res[n%10] += t;
		n /= 10;
	}
}
void solve(int s, int e, int t=1)
{
	while(1)
	{
		if(s % 10 == 0 || s > e) break;
		count(s++, t);
	}
	if(s > e) return;
	while(1)
	{
		if(e % 10 == 9 || s > e) break;
		count(e--, t);
	}
	s /= 10; e /= 10;
	for(int i = 0; i < 10; ++i)
		res[i] += (e-s+1)*t;
	solve(s, e, t*10);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	int n; cin >> n;
	solve(1,n);
	for(int i = 0; i < 10; ++i)
		cout << res[i] << ' ';
	cout << '\n';
}//g++ -o a -std=c++11 *.cpp