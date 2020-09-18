// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <functional>

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
	int res = 0;
	while(pq.size() != 1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		res += (a+b);
		pq.push(a+b);
	}
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;