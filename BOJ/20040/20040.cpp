// https://www.acmicpc.net/problem/20040
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[500001];
int p(int a)
{
	if(arr[a] < 0) return a;
	return arr[a] = p(arr[a]);
}
bool merge(int a, int b)
{
	a = p(a);
	b = p(b);
	if(a == b) return false;
	arr[b] = a;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	std::fill(arr, arr+n+1, -1);

	int res = 0;
	for(int i = 1; i <= m; ++i)
	{
		int a,b; cin >> a >> b;
		if(a>b) std::swap(a,b);
		if(res == 0 && false == merge(a,b)) res = i;
	}
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp