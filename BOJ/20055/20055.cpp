// https://www.acmicpc.net/problem/20055
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <deque>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k; cin >> n >> k;
	std::deque<pii> d;
	for(int i = 0; i < 2*n; ++i)
	{
		int x; cin >> x;
		d.push_back({x,0});
	}

	int res = 0, cnt = 0;
	while(cnt < k)
	{
		d.push_front(d.back());
		d.pop_back();
		d[n-1].second = 0;

		for(int i = n-2; i >= 0; --i)
		{
			auto &curr = d[i];
			auto &next = d[i+1];

			if(curr.second == 1 && next.first != 0 && next.second == 0)
			{
				if(--next.first == 0) cnt++;
				next.second = 1;

				curr.second = 0;
			}
		}
		d[n-1].second = 0;
		
		auto &front = d.front();
		if(front.first != 0 && front.second == 0)
		{
			if(--front.first == 0) cnt++;
			front.second = 1;
		}

		res++;
	}

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp