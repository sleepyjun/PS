// https://www.acmicpc.net/problem/2252
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

std::vector<int> next[32001];
int prev[32001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int a,b; cin >> a >> b;
		prev[b]++;
		next[a].push_back(b);
	}

	std::queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(prev[i] == 0) q.push(i);

	while(!q.empty())
	{
		int curr = q.front(); q.pop();
		for(int n : next[curr])
		{
			prev[n]--;
			if(prev[n] == 0) q.push(n);
		}
		cout << curr << ' ';
	}
	cout << '\n';
}//g++ -o a -std=c++11 *.cpp