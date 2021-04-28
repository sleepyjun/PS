// https://www.acmicpc.net/problem/1766
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int indegree[32001];
std::vector<int> adj[32001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	int n,m; cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a,b; cin >> a >> b;
		indegree[b]++;
		adj[a].push_back(b);
	}
	for(int i = 1; i <= n; ++i)
	{
		std::sort(adj[i].begin(), adj[i].end());
		if(indegree[i] == 0) pq.push(i);
	}

	for(int i = 0; i < n; ++i)
	{
		int curr = pq.top(); pq.pop();
		cout << curr << ' ';
		for(int next: adj[curr])
		{
			if(--indegree[next] == 0) pq.push(next);
		}
	}
	cout << '\n';
}//g++ -o a -std=c++11 *.cpp