// https://www.acmicpc.net/problem/18290
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[13][13];
int n, m, k;
int arr[11][11];
int res = -999999;

bool safe(int y, int x)
{
	if(y < 1 || y > n || x < 1 || x > m) return false;
	if(visited[y+1][x] == true) return false;
	if(visited[y-1][x] == true) return false;
	if(visited[y][x+1] == true) return false;
	if(visited[y][x-1] == true) return false;
	return true;
}
void dfs(int sum = 0, int cnt = 0)
{
	if(cnt == k)
	{
		res = std::max(res,sum);
		return;
	}
	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= m; ++x)
		{
			if(false == visited[y][x] && true == safe(y,x))
			{
				visited[y][x] = true;
				dfs(sum+arr[y][x],cnt+1);
				visited[y][x] = false;
			}
		}
	}
	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&arr[0][0], &arr[10][11], INF);
	cin >> n >> m >> k;
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			cin >> arr[y][x];
	dfs();
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp