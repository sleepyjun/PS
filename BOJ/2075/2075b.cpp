// https://www.acmicpc.net/problem/2075
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
	
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		pq.push(x);
	}
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int x; cin >> x;
			pq.push(x);
		}
		for(int j = 0; j < n; ++j)
			pq.pop();
	}
	
	cout << pq.top() << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;