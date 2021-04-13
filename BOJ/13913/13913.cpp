// https://www.acmicpc.net/problem/13913
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

int visited[100001];

bool position(int n)
{
	if(n < 0 || n > 100000) return false;
	if(visited[n] != -2) return false;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	std::fill(visited, visited+100001, -2);

	int cnt = 0;
	std::queue<int> q;
	q.push(n); visited[n] = -1;
	while(!q.empty())
	{
		if(n==k) break;
		bool flag = false;
		int qSize = q.size();
		for(int i = 0; i < qSize; ++i)
		{
			int curr = q.front(); q.pop();
			int next = curr-1;

			if(true == position(next))
			{
				visited[next] = curr;
				if(next == k)
				{
					flag = true;
					break;
				}
				q.push(next);
			} next = curr+1;
			if(true == position(next))
			{
				visited[next] = curr;
				if(next == k)
				{
					flag = true;
					break;
				}
				q.push(next);
			} next = curr*2;
			if(true == position(next))
			{
				visited[next] = curr;
				if(next == k)
				{
					flag = true;
					break;
				}
				q.push(next);
			}
		}
		cnt++;
		if(true == flag) break;
	}

	std::vector<int> path;
	while(visited[k] != -1)
	{
		path.push_back(k);
		k = visited[k];
	} path.push_back(n);
	std::reverse(path.begin(), path.end());
	
	cout << cnt << '\n';
	for(int x: path)
		cout << x << ' ';
}//g++ -o a -std=c++11 *.cpp