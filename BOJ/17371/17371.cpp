// https://www.acmicpc.net/problem/17371
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int distance(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<pii> arr;
	for(int i = 0; i < n; ++i)
	{
		int x,y; cin >> x >> y;
		arr.push_back({x,y});
	}

	int min = INF;
	int r = 0;
	for(int i = 0; i < n; ++i)
	{
		int max = 0;
		int t = i;
		for(int j = 0; j < n; ++j)
		{	
			if(i==j)continue;
			int dist = distance(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
			if(dist > max)
			{
				max = dist;
				t = i;
			}
		}
		if(max < min)
		{
			min = max;
			r = t;
		}
	}

	cout << arr[r].first << ' ' << arr[r].second << '\n';
}//g++ -o a -std=c++11 *.cpp