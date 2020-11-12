// https://www.acmicpc.net/problem/13549
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

bool visited[100001];
bool position(int n)
{
	if(n < 0 || n > 100000) return false;
	if(visited[n] == true) return false;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	int time = 0;
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq; // location and time
	pq.push({time,n}); visited[n] = true;
	while(!pq.empty())
	{
		const auto curr = pq.top(); pq.pop();
		int currTime = curr.first;
		int currLocation = curr.second;
		if(currLocation == k)
		{
			cout << currTime << '\n';
			return 0;
		}

		if(true == position(currLocation*2))
		{
			pq.push({currTime, currLocation*2});
			visited[currLocation*2] = true;
		}
		if(true == position(currLocation+1))
		{
			pq.push({currTime+1, currLocation+1});
			visited[currLocation+1] = true;
		}
		if(true == position(currLocation-1))
		{
			pq.push({currTime+1, currLocation-1});
			visited[currLocation-1] = true;
		}
	}
}//g++ -o a -std=c++11 *.cpp -g