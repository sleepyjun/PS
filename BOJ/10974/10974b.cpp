// https://www.acmicpc.net/problem/10974
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;
int res[8];
bool visited[9];
void dfs(int curr)
{
	if(curr == n)
	{
		for(int i = 0; i < n; ++i)
			cout << res[i] << ' ';
		cout << '\n';
	}
	for(int i = 1; i <= n; ++i)
	{
		if(visited[i] == true) continue;
		visited[i] = true;
		res[curr] = i;
		dfs(curr+1);
		visited[i] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	dfs(0);
}//g++ -o a -std=c++17 *.cpp