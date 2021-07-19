// https://www.acmicpc.net/problem/6209
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int d, n, m; cin >> d >> n >> m;
	int l = 0, r = d;
	std::vector<int> rocks(n);

	for(int i = 0; i < n; ++i)
		cin >> rocks[i];
	rocks.push_back(d);
	std::sort(rocks.begin(), rocks.end());

	int res;
	while(l <= r)
	{
		int dist = (l+r)/2;
		int temp = INF;
		int cnt = 0;
		int pos = 0;

		for(int rock: rocks)
		{
			int tDist = rock-pos;
			if(dist > tDist) cnt++;
			else
			{
				temp = std::min(temp, tDist);
				pos = rock;
			}
		}
		if(cnt > m) r = dist-1;
		else
		{
			l = dist+1;
			res = temp;
		}
	}

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp