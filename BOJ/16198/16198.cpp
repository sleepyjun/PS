// https://www.acmicpc.net/problem/16198
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int cnt = 1;
int n;
std::vector<int> arr;

void print(std::vector<int> &arr)
{
	cout << cnt++ << "th array: ";
	for(int x: arr)
		cout << x << ' ';
	cout << '\n';
}
int dfs(std::vector<int> arr)
{
	int size = arr.size();
	if(size <= 2) return 0;
	int ret = -1;

	for(int i = 1; i < size-1; ++i)
	{
		int x = arr[i];
		arr.erase(arr.begin()+i);
		ret = std::max(ret, dfs(arr) + arr[i-1]*arr[i]);
		arr.insert(arr.begin()+i, x);
	}

	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		arr.push_back(x);
	}
	cout << dfs(arr) << '\n';
}//g++ -o a -std=c++17 *.cpp