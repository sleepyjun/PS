#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using std::cin; using std::cout;

std::vector<int> adj[101];
int visited[101];
int res[101];
int n;
void bfs(int node)
{
	std::queue<int> q;
	int depth = 1;
	
	q.push(node);
	visited[node] = -1;
	
	while(!q.empty())
	{
		int qSize = q.size();
		for(int i = 0; i < qSize; ++i)
		{
			int curr = q.front(); q.pop();
			for(int i = 0; i < adj[curr].size(); ++i)
			{
				if(visited[adj[curr].at(i)] == 0)
				{
					visited[adj[curr].at(i)] = depth;
					q.push(adj[curr].at(i));
				}
			}
		}
		depth++;
	}
	
	for(int i = 1; i <= n; ++i)
		if(i != node) res[node] += visited[i];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m; cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		std::fill(visited, visited+101, 0);
		bfs(i);
	}
	
	int min = 987654321;
	int idx;
	for(int i = 1; i <= n; ++i)
	{
		if(min > res[i])
		{
			min = res[i];
			idx = i;
		}
	}
	cout << idx << '\n';
}