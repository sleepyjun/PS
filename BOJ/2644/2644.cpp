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

std::vector<int> adj[101];
bool visited[101];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int src, dest;
	cin >> src >> dest;
	int m; cin >> m;
	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	std::queue<int> q;
	int level = -1;
	bool flag = true;
	
	q.push(src);
	while(!q.empty() && flag)
	{
		int qSize = q.size();
		for(int i = 0; flag && i < qSize; ++i)
		{
			int curr = q.front(); q.pop();
			if(curr == dest)
				flag = false;
			
			for(int next : adj[curr])
			{
				if(!visited[next])
				{
					visited[next] = true;
					q.push(next);
				}
			}
		}
		level++;
	}
	
	if(flag == true) cout << -1;
	else cout << level;
	cout << '\n';
}