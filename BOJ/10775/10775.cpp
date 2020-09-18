// https://www.acmicpc.net/problem/10775
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int p[100001];
int arr[100001];
int find(int n)
{
	if(p[n] == n) return n;
	return p[n] = find(p[n]);
}
// void merge(int p, int c)
// {
// 	p = find(p);
// 	c = find(c);
// 	if(p == c) return;
// 	arr[p] += arr[c];
// 	arr[c] = p;
// }
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int G,P; cin >> G >> P;
	for(int i = 0; i <= G; ++i) p[i] = i;
	for(int i = 0; i < P; ++i) cin >> arr[i];
	int cnt = 0;
	for(int i = 0; i < P; ++i)
	{
		int w = find(arr[i]);
		if(w > 0)
		{
			p[w] = w-1;
			cnt++;
		}
		else break;
	}
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;