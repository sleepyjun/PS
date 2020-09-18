#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

std::vector<int> adj[1001];
bool visited[1001];
bool connected(int n)
{
	std::queue<int> q;
	q.push(n);
	while(false == q.empty())
	{
		int here = q.front();
		visited[here] = true; q.pop();
		for(const auto& next : adj[here])
		{
			if(true == visited[next])
				continue;
			q.push(next);
		}
	}
	
	for(int i = 1; i <= n; ++i)
		if(visited[i] == false) return false;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n,m,a,b;
		cin >> n >> m;
		for(int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		if(n-1 == m && connected(n))
			cout << "tree";
		else
			cout << "graph";
		cout << '\n';
		
		for(int i = 1; i <= n; ++i)
			adj[i].clear();
		std::fill(visited, visited+n+1, false);
	}
}