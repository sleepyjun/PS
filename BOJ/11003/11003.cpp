// https://www.acmicpc.net/problem/11003
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
	
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
	int n,l; cin >> n >> l;
	for(int i = 0; i < n; ++i)
	{
		int r = i-l;
		int x; cin >> x;
		pq.push({x,i});
		while(pq.top().second <= r) pq.pop();
		cout << pq.top().first << ' ';
	}
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;