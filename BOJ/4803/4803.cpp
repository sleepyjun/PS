// https://www.acmicpc.net/problem/4803
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

std::vector<int> adj[501];
bool visited[501];

int bfs(int root)
{
	int cnt=0;
	std::queue<int> q;
	q.push(root); visited[root] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int next : adj[curr])
		{
			cnt++;
			if(visited[next] == true) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	
	cout << cnt << '\n';
	return 0;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		int n,m; cin >> n >> m;
		if(n==m && n==0) return 0;
		for(int i = 0; i < m; ++i)
		{
			int a,b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int res = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(!adj[i].empty() && !visited[i])
			{
				res+=bfs(i);
			}
			else res++;
		}
		
		for(int i = 0; i <= n; ++i)
			adj[i].clear();
		std::fill(visited, visited+n+1, false);
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;