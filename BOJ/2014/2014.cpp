// https://www.acmicpc.net/problem/2014
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::map<ull, int> visited;
	std::priority_queue<ull, std::vector<ull>, std::greater<ull> > pq;
	int arr[100];
	int k, n; cin >> k >> n;
	ull max = 0;
	
	for(int i = 0; i < k; ++i)
	{
		cin >> arr[i];
		pq.push(arr[i]);
		max = std::max(max,(ull)arr[i]);
		visited[arr[i]] = 1;
	}
	ull prev;
	int cnt = 0;
	while(1)
	{
		prev = pq.top();
		pq.pop(); cnt++;
		if(cnt == n) break;
		for(int i = 0; i < k; ++i)
		{
			ull temp = prev*arr[i];
			if(temp > max && pq.size() > n) break;
			if(visited[temp] == 1) continue;
			visited[temp] = 1;
			max = std::max(max, temp);
			pq.push(temp);
		}
	}
	cout << prev << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;