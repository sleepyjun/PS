// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[1000001];
int find(int n)
{
	if(arr[n] < 0) return n;
	arr[n] = find(arr[n]);
	return arr[n];
}
void merge(int parent, int child)
{
	parent = find(parent);
	child = find(child);
	if(parent == child) return;
	arr[parent] += arr[child];
	arr[child] = parent;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	std::fill(arr, arr+n+1, -1);
	while(m--)
	{
		int q,a,b; cin >> q >> a >> b;
		if(q == 0)
		{
			merge(a,b);
		}
		else
		{
			if(find(a) == find(b))
				cout << "YES";
			else
				cout << "NO";
			cout << '\n';
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;