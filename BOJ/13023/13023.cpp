// https://www.acmicpc.net/problem/13023
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> adj[2001];
bool visited[2001];

void run(int curr, int cnt=0)
{
	if(cnt == 4)
	{
		cout << 1 << '\n';
		exit(0);
	}
	visited[curr] = true;
	for(int n: adj[curr])
	{
		if(visited[n] == true) continue;
		run(n, cnt+1);
	}
	visited[curr] = false;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 0; i < n; ++i)
	{
		// std::fill(visited, visited+2001, false);
		run(i);
	}
	cout << 0 << '\n';
}//g++ -o a -std=c++17 *.cpp