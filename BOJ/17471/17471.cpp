// https://www.acmicpc.net/problem/17471
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = 250000;

int pop[11];
std::vector<int> adj[11];

int run(const std::vector<bool> &v)
{
	std::vector<bool> visited(v);
	int ret = INF;
	int node = 0;

	for(bool flag: visited)
	{
		if(flag == false)
			break;
		node++;
	}
	if(visited.size() == node) return INF;
	
	std::queue<int> q;
	
	q.push(node); 
	visited[node] = true;
	ret = pop[node];

	while(!q.empty())
	{
		int curr = q.front(); q.pop();

		for(int next: adj[curr])
		{
			next--;
			if(false == visited[next])
			{
				q.push(next);
				visited[next] = true;
				ret += pop[next];
			}
		}
	}

	for(bool flag: visited)
		if(flag == false)
			return INF;
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> pop[i];
	for(int i = 0; i < n; ++i)
	{
		int cnt; cin >> cnt;
		for(int j = 0; j < cnt; ++j)
		{
			int x; cin >> x;
			adj[i].push_back(x);
		}
	}

	int ans = INF;
	for(int i = 1; i <= n/2; ++i)
	{
		std::vector<int> arr(n, 1);
		for(int j = 0; j < i; ++j) arr[j] = 0;

		do
		{
			std::vector<bool> visit;
			for(int node: arr)
				if(node == 0) visit.push_back(false);
				else visit.push_back(true);
			
			int zerosum = run(visit); visit.flip();
			int onesum = run(visit);

			if(zerosum == INF || onesum == INF) continue;
			
			ans = std::min(ans, abs(zerosum-onesum));
		} while (std::next_permutation(arr.begin(), arr.end()));
	}

	cout << (ans == INF ? -1 : ans) << '\n';
}//g++ -o a -std=c++17 *.cpp