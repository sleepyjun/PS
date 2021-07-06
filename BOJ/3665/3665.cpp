// https://www.acmicpc.net/problem/3665
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

const int MAX = 501;

int price[MAX];
int indegree[MAX];
int result[MAX];
bool adj[MAX][MAX];
// if true is i -> j path alive;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> price[i];
		for(int i = 0; i < n; ++i)
		{
			int a = price[i];
			for(int j = i+1; j < n; ++j)
			{
				int b = price[j];
				indegree[b]++;
				adj[a][b] = true;
			}
		}
		int m; cin >> m;
		for(int i = 0; i < m; ++i)
		{
			int a,b; cin >> a >> b;
			
			if(adj[a][b] == true)
			{
				indegree[b]--;
				indegree[a]++;
			}
			else if(adj[b][a] == true)
			{
				indegree[a]--;
				indegree[b]++;
			}
			std::swap(adj[a][b], adj[b][a]);
		}

		bool flag = false;
		std::queue<int> q;
		for(int i = 1; i <= n; ++i)
			if(indegree[i] == 0) q.push(i);

		for(int i = 0; i < n; ++i)
		{
			if(q.empty() || q.size() > 1)
			{
				flag = true;
				break;
			}

			int curr = q.front(); q.pop();
			result[i] = curr;
			for(int next = 1; next <= n; ++next)
			{
				if(adj[curr][next] == 1)
				{
            		if(--indegree[next] == 0) q.push(next);
				}
			}
		}

		if(flag == false)
			for(int i = 0; i < n; ++i) cout << result[i] << ' ';
		else cout << "IMPOSSIBLE";
		cout << '\n';

		std::fill(price, price+501, 0);
		std::fill(indegree, indegree+501, 0);
		std::fill(result, result+501, 0);
		std::fill(&adj[0][0], &adj[500][501], 0);
	}
}//g++ -o a -std=c++17 *.cpp