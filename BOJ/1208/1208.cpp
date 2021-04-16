// https://www.acmicpc.net/problem/1208
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[41];
int half;
int n, s;
long long res = 0;
std::map<int, int> m;

void dfs(int curr, int sum = 0)
{
	if(curr == half)
	{
		int &a = m[sum];
		if(a != 0) a++;
		else a = 1;

		return;
	}
	dfs(curr+1, sum+arr[curr]);
	dfs(curr+1, sum);
}
void _dfs(int curr, int sum = 0)
{
	if(curr == n)
	{
		int &a = m[s-sum];
		if(a != 0) res += a;
		return;
	}
	_dfs(curr+1, sum+arr[curr]);
	_dfs(curr+1, sum);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	half = n/2;
	dfs(0);
	_dfs(half);
	cout << (s==0? res-1: res) << '\n';
	return 0;
}//g++ -o a -std=c++11 *.cpp