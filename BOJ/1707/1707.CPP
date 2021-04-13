// https://www.acmicpc.net/problem/1707
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


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int v,e; cin >> v >> e;
		std::vector<int> adj[20001];
		int visited[20001];
		
		std::fill(visited, visited+20001, -1);
		for(int i = 0; i < e; ++i)
		{
			int a,b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		bool ans = true;
		for(int i = 1; ans && i <= v; ++i)
		{
			if(visited[i] != -1) continue;
			std::queue<int> q;
			int flag = 0;
			q.push(i);
			visited[i] = flag;
			while(!q.empty() && ans)
			{
				int curr = q.front(); q.pop();
				flag = (visited[curr] == 0 ? 1 : 0);
				for(int next: adj[curr])
				{
					if(visited[next] == -1)
					{
						visited[next] = flag;
						q.push(next);
					}
					else //already visited
						if(visited[next] != flag)
							ans = false;
				}
			}
		}
		if(ans == false) cout << "NO\n";
		else cout << "YES\n";
	}
}//g++ -o a -std=c++11 *.cpp