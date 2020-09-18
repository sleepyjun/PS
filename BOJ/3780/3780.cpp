// https://www.acmicpc.net/problem/3780
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[20001], dist[20001];
int find(int n)
{
	if(arr[n] < 0) return n;
	int p = find(arr[n]);
	dist[n] += dist[arr[n]];
	return arr[n] = p;
}
void merge(int p, int c)
{
	arr[p] = c;
	dist[p] = abs(p-c)%1000;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		std::fill(arr,arr+n+1,-1);
		std::fill(dist,dist+n+1,0);
		while(1)
		{
			char ch; cin >> ch;
			if(ch == 'O') break;
			else if(ch == 'E')
			{
				int x; cin >> x;
				find(x);
				cout << dist[x] << '\n';
				// for(int i = 1; i <= n; ++i)
				// 	cout << dist[i] << ' ';
				// cout << '\n';
			}
			else if(ch == 'I')
			{
				int p,c; cin >> p >> c;
				merge(p,c);
			}
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;