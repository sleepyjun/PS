// https://www.acmicpc.net/problem/2696
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
		int m; cin >> m;
		std::priority_queue<int> maxHeap;
		std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
		std::vector<int> v;
		for(int i = 1; i <= m; ++i)
		{
			int x; cin >> x;
			if(maxHeap.size() == minHeap.size()) maxHeap.push(x);
			else minHeap.push(x);
			
			if(!maxHeap.empty() && !minHeap.empty())
			{
				int a = maxHeap.top();
				int b = minHeap.top();
				if(a > b)
				{
					maxHeap.pop(); minHeap.pop();
					maxHeap.push(b); minHeap.push(a);
				}
			}
			if(i%2) v.push_back(maxHeap.top());
			
		}
		int res = v.size();
		cout << res << '\n';
		for(int i = 0; i < res; ++i)
		{
			cout << v[i];
			if((i+1)%10) cout << ' ';
			else cout << '\n';
		}
		if(res%10) cout << '\n';
	}
	
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;