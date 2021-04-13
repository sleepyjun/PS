// // https://www.acmicpc.net/problem/16928
// #include <iostream>
// #include <algorithm>
// #include <limits>
// #include <vector>
// #include <string>
// #include <queue>

// using std::cin; using std::cout;
// using ull = unsigned long long;
// using pii = std::pair<int, int>;
// const int INF = std::numeric_limits<int>::max();

// int warp[101];
// int visited[101];

// int main()
// {
// 	std::ios_base::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);
	
// 	int n, m; cin >> n >> m;
// 	for(int i = 0; i < n; ++i)
// 	{
// 		int u,v; cin >> u >> v;
// 		warp[u] = v;
// 	}

// 	for(int i = 0; i < m; ++i)
// 	{
// 		int u,v; cin >> u >> v;
// 		warp[u] = v;
// 	}

// 	std::fill(visited, visited+101, -1);
// 	std::queue<int> q;
// 	q.push(1); visited[1] = 0;
// 	while(!q.empty())
// 	{
// 		int cw = q.front(); q.pop();
// 		for(int i = 1; i <= 6; ++i)
// 		{
// 			int nw = cw + i;
// 			if(nw > 100) break;

// 			if(warp[nw]) nw = warp[nw];
// 			if(visited[nw] == -1)
// 			{
// 				visited[nw] = visited[cw] + 1;
// 				q.push(nw);
// 			}
// 		}
// 	}

// 	cout << visited[100] << '\n';
// }//g++ -o a -std=c++11 *.cpp

// https://www.acmicpc.net/problem/16928
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

int warp[101];
bool visited[101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		int u,v; cin >> u >> v;
		warp[u] = v;
	}

	for(int i = 0; i < m; ++i)
	{
		int u,v; cin >> u >> v;
		warp[u] = v;
	}

	int res = INF;
	std::queue<pii> q;
	q.push({1,0}); visited[1] = true;
	while(!q.empty())
	{
		const auto& curr = q.front();
		int cw = curr.first;
		int ccnt = curr.second;
		q.pop();

		if(cw == 100) 
		{
			res = std::min(res, ccnt);
			continue;
		}

		for(int i = 1; i <= 6; ++i)
		{
			int nw = (warp[nw] != 0 ? warp[nw] : cw+i);
			if(nw > 100) break;
			if(false == visited[nw])
			{
				visited[nw] == true;
				q.push({nw, ccnt+1});
			}
		}
	}

	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp