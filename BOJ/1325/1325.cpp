#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using std::cin; using std::cout;

int n, m;
std::vector<std::vector<int> > v;
std::vector<int> ans;
bool visited[10001];

void bfs()
{
	int prev = 0, cnt;
	std::queue<int> q;
	for(int i = 1; i <= n; ++i)
	{
		cnt = 0;
		std::fill(visited, visited+n+1, false);
		q.push(i); visited[i] = true;
		while(!q.empty())
		{
			int node = q.front(); q.pop();
			
			for(int j = 0; j < v[node].size(); ++j)
			{
				int next = v[node][j];
				if(visited[next] == false)
				{
					visited[next] = true;
					cnt++;
					q.push(next);
				}
			}
		}
		if(prev < cnt)
		{
			ans.clear(); prev = cnt;
		}
		if(cnt == prev) ans.push_back(i);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	v.resize(n+1);
	
	for(int i = 0; i < m; ++i)
	{
		int A,B; cin >> A >> B;
		v[B].push_back(A);
	}
	bfs();
	std::sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}