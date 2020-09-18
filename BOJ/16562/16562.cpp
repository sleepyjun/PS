// https://www.acmicpc.net/problem/16562
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[10001];
int cost[10001];

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
	if(cost[p] > cost[c]) std::swap(p,c);
	arr[p] += arr[c];
	arr[c] = p;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,k; cin >> n >> m >> k;
	std::fill(arr, arr+n+1, -1);
	for(int i = 1; i <= n; ++i) cin >> cost[i];
	for(int i = 0; i < m; ++i)
	{
		int a,b; cin >> a >> b;
		if(a > b) std::swap(a,b);
		merge(a,b);
	}
	int res = 0;
	for(int i = 1; i <= n; ++i)
		if(arr[i] < 0) res += cost[i];
	if(res <= k) cout << res << '\n';
	else cout << "Oh no\n";
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;