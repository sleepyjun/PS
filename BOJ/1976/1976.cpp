// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[201];
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
	
	int n,m; cin >> n >> m;
	std::fill(arr,arr+n+1,-1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			int x; cin >> x;
			if(x == 1)
				merge(i,j);
		}
	}
	
	std::vector<int> travel(m);
	for(int i = 0; i < m; ++i)
		cin >> travel[i];
	int prev = find(travel[0]);
	bool flag = true;
	for(int i = 1; flag && i < m; ++i)
	{
		int curr = find(travel[i]);
		if(prev == curr)
			prev = curr;
		else flag = false;
	}
	if(flag) cout << "YES";
	else cout << "NO";
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;