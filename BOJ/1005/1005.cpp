// https://www.acmicpc.net/problem/1005
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
		int n,k;
		int time[1001];
		int pre[1001];
		std::vector<int> next[1001];
		std::queue<int> q;
		/*========================*/
		std::fill(time,time+1001,0);
		std::fill(pre,pre+1001,0);
		/*========================*/
		cin >> n >> k;
		for(int i = 1; i <= n; ++i)
			cin >> time[i];
		for(int i = 0; i < k; ++i)
		{
			int x, y; cin >> x >> y;
			next[x].push_back(y);
			pre[y]++;
		}
		int w; cin >> w;
		int minTime[1001];
		std::fill(minTime, minTime+1001, 0);
		for(int i = 1; i <= n; ++i)
			if(pre[i] == 0) q.push(i);
		while(pre[w] > 0)
		{
			int n = q.front();
			q.pop();
			for(int next : next[n])
			{
				minTime[next] = std::max(minTime[next], minTime[n] + time[n]);
				pre[next]--;
				if(pre[next] == 0) q.push(next);
			}
		}

		cout << minTime[w]+time[w] << '\n';
	}
}//g++ -o a -std=c++11 *.cpp