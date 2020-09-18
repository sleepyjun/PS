#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[100001];
bool finished[100001];
bool visited[100001];
int cnt = 0;

void dfs(int node)
{
	visited[node] = true;
	int next = arr[node];
	if(visited[next])
	{
		if(!finished[next])
		{
			for(int i = next; i != node; i = arr[i]) cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finished[node] = true;	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> arr[i];
		
		std::fill(finished, finished+n+1, false);
		std::fill(visited, visited+n+1, false);
		cnt = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(!visited[i])
				dfs(i);
		}
		
		cout << n-cnt << '\n';
	}
}