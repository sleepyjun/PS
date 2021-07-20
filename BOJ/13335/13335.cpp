// https://www.acmicpc.net/problem/13335
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

int truck[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(truck, truck+1001, 10000);
	int n,w,l; cin >> n >> w >> l;
	std::queue<int> q;
	
	for(int i = 0; i < n; ++i)
		cin >> truck[i];

	int ans = 0;
	int currWeight = 0;
	for(int i = 0; i < n; ++i)
	{
		q.push(truck[i]);
		currWeight += truck[i];
		ans++;
		while(1)
		{
			if(q.size() == w)
			{
				currWeight -= q.front();
				q.pop();
			}
			if(i == n-1 || currWeight + truck[i+1] <= l) break;
			q.push(0);
			ans++;
		}
	}

	cout << ans+w << '\n';
}//g++ -o a -std=c++17 *.cpp