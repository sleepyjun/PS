// https://www.acmicpc.net/problem/2001
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

int JEWEL = 0; //bitmasking not using 0th bit
int ISLAND[15];
std::vector<pii> adj[101];
int dp[101];
bool visited[101][(1<<15)];
int count(int status)
{
	int cnt = 0;
	for(int i = 1; i <= 14; ++i)
		if(status & (1<<i)) cnt++;
	return cnt;
}
int check(int node)
{
	for(int i = 1; i <= 14; ++i)
		if(ISLAND[i] == node) return i;
	return -1;
}
int func()
{
	std::queue<pii> q;
	q.push({1,0});
	
	while(!q.empty())
	{
		auto curr = q.front(); q.pop();
		int cNode = curr.first;
		int cStatus = curr.second;
		
		for(auto next : adj[cNode])
		{
			int have = count(cStatus);
			if(have > next.second) continue;
			if(visited[next.first][cStatus] == true) continue;
			visited[next.first][cStatus] = true;
			if(have < dp[next.first]) have = dp[next.first];
			else dp[next.first] = have;
			
			int jewelIsland = check(next.first);
			
			if(jewelIsland != -1) 
			{
				if(!(cStatus & (1<<jewelIsland)))
					q.push({next.first, cStatus|(1<<jewelIsland)});
			}
			q.push({next.first, cStatus});
		}
	}
	if(check(1) != -1) dp[1]++;
	return dp[1];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,k; cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i)
	{
		int x; cin >> x;
		ISLAND[i] = x;
		JEWEL |= (1<<i);
	}
	for(int i = 0; i < m; ++i)
	{
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	cout << func() << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;