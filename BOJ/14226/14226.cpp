// https://www.acmicpc.net/problem/14226
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using iii = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[1001][1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int s; cin >> s;

	std::queue<iii> q;
	q.push({1,0,0}); visited[0][0] = visited[1][0] = true;

	int res = INF;
	while(!q.empty())
	{
		int cnt, time, save;
		std::tie(cnt, time, save) = q.front();
		q.pop();

		if(s == cnt)
		{
			res = std::min(res, time);
			continue;
		}

		int newCnt = cnt+save;
		if(newCnt > 1000) continue;
		if(visited[newCnt][save] == false)
		{
			visited[newCnt][save] = true;
			q.push({newCnt, time+1, save});
		}

		newCnt = cnt-1;
		if(newCnt < 0) continue;
		if(visited[newCnt][save] == false)
		{
			visited[newCnt][save] = true;
			q.push({newCnt, time+1, save});
		}

		if(cnt > 1000) continue;
		if(visited[cnt][cnt] == false)
		{
			visited[cnt][cnt] = true;
			q.push({cnt, time+1, cnt});
		}
	}

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp