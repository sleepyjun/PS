// https://www.acmicpc.net/problem/4195
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[100001];

int find(int n)
{
	if(arr[n] < 0) return n;
	return arr[n] = find(arr[n]);
}
void merge(int p, int c)
{
	p = find(p);
	c = find(c);
	if(p == c) return;
	arr[p] += arr[c];
	arr[c] = p;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(arr,arr+100001,-1);
		std::map<std::string, int> m;
		int f; cin >> f;
		int cnt = 1;
		for(int i = 0; i < f; ++i)
		{
			std::string a,b; cin >> a >> b;
			
			if(m[a] == 0)
				m[a] = cnt++;
			if(m[b] == 0)
				m[b] = cnt++;
			merge(m[a],m[b]);
			cout << abs(arr[find(m[a])]) << '\n';
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;